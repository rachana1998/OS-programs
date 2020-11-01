#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int a,b;
int sum;
sem_t s1,s2;

void *Input_thread(void *arg)
{
while(1)
{
printf("IN INPUT THREAD STARTING\n");
sem_wait(&s2); //lock
printf("T1:got signal from processing thread to take inputs\n");
scanf("%d",&a);
scanf("%d",&b);
printf("T1:sending signal to processing thread to add\n");
sem_post(&s1); //unlock
printf("IN INPUT THREAD ENDING\n");
}
}

void *Processing_thread(void *arg)
{
while(1)
{
printf("IN PROCESSING THREAD STARTING\n");
sem_wait(&s1); //lock
printf("T2 :adding inputs for sum\n");
sum=a+b;
printf("T2 : sum is %d\n",sum);
printf("T2:sending signal to input thread to take inputs\n");
sem_post(&s2); //unlock
printf("IN PROCESS THREAD ENDING \n");
}
}


int main()
{
pthread_t tid1,tid2;

sem_init(&s1,0,0); 
sem_init(&s2,0,1);

pthread_create(&tid1,NULL,Input_thread,NULL);
pthread_create(&tid2,NULL,Processing_thread,NULL);
pthread_join(tid1,NULL);//joining the thread to main
pthread_join(tid2,NULL);

sem_destroy(&s1);
sem_destroy(&s2); //destroying semaphore
return 0;
}

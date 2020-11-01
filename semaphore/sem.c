#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int count=0;
sem_t semaphore;

void *Inc_thread(void *arg)
{
while(1)
{
sem_wait(&semaphore); //lock
count++;
printf("Inc thread: %d\n",count);
sem_post(&semaphore); //unlock
}
}
void *Dec_thread(void *arg)
{
while(1)
{
sem_wait(&semaphore); //lock
count--;
printf("Dec thread: %d\n",count);
sem_post(&semaphore); //unlock
}
}


int main()
{
pthread_t tid1,tid2;
sem_init(&semaphore,0,1); //0 means process shared by threads and 1 means intial value for lock should be one

pthread_create(&tid1,NULL,Inc_thread,NULL);
pthread_create(&tid2,NULL,Dec_thread,NULL);
pthread_join(tid1,NULL);//joining the thread to main
pthread_join(tid2,NULL);

sem_destroy(&semaphore); //destroying semaphore
return 0;
}

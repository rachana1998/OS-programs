#include<stdio.h>
#include<pthread.h>


int flag=0;
pthread_mutex_t mutex;
pthread_cond_t *cv;
void *thread1(void* arg)
{
printf("T1:grabbing mutex \n");
pthread_mutex_lock(&mutex);

printf("T1: before busyloop\n");
while(flag==0)
{
	printf("entering conditional wait\n");
	pthread_cond_wait(&cv,&mutex);
	printf("exiting conditional wait\n");
}

printf("T1: after busyloop\n");

pthread_mutex_unlock(&mutex);
printf("T1: unlocking mutex\n");
}

void *thread2(void* arg)
{
printf("T2: grabbing mutex\n");
pthread_mutex_lock(&mutex);
flag=1;
pthread_mutex_unlock(&mutex);
printf("T2: releasing mutex\n");
pthread_cond_signal(&cv);
printf("T2: signalling cv\n");
}

int main()
{
pthread_t a,b;

pthread_mutex_init(&mutex,NULL);
pthread_cond_init(&cv,NULL);

pthread_create(&a,NULL,thread1,NULL);
pthread_create(&b,NULL,thread2,NULL);

pthread_join(a,NULL);
pthread_join(b,NULL);

pthread_mutex_destroy(&mutex);
pthread_cond_destroy(&cv);
return 0;
}

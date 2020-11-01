#include<stdio.h>
#include<pthread.h>

int count=0;
pthread_mutex_t mutex;
pthread_mutexattr_t mutex_attribute;

void *Inc_thread(void *arg)
{
while(1)
{
pthread_mutex_lock(&mutex); //locking the mutex
count++;
printf("Inc_thread: %d \n",count);
pthread_mutex_unlock(&mutex); //unlocking the mutex
}
}

void *Dec_thread(void *arg)
{
while(1)
{
pthread_mutex_lock(&mutex); //locking the mutex
pthread_mutex_lock(&mutex); //leads to deadlock
count--; 
printf("Dec thread: %d \n",count);
pthread_mutex_unlock(&mutex);
}
}

int main()
{
pthread_t tid_Inc, tid_Dec;

pthread_mutexattr_init(&mutex_attribute);
pthread_mutex_init(&mutex,&mutex_attribute);

pthread_create(&tid_Inc,NULL,Inc_thread,NULL);
pthread_create(&tid_Dec,NULL,Dec_thread,NULL);

pthread_join(tid_Inc,NULL);
pthread_join(tid_Dec,NULL);

pthread_mutex_destroy(&mutex);
pthread_mutexattr_destroy(&mutex_attribute);

return 0;
}

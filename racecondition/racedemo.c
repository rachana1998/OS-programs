#include<stdio.h>
#include<pthread.h>
int count=0;
void *Inc_thread(void *arg)
{
while(1)
{
count++;
printf("Inc thread: %d\n",count);
}
}
void *Dec_thread(void *arg)
{
while(1)
{
count--;
printf("Dec thread: %d\n",count);
}
}
int main()
{
pthread_t tid1,tid2;
pthread_create(&tid1,NULL,Inc_thread,NULL);
pthread_create(&tid2,NULL,Dec_thread,NULL);
pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
return 0;
}

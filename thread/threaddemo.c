#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *thread(void *arg)
{
printf("in thread now\n");
}
int main()
{
pthread_t tid;
printf("before thread\n");
pthread_create(&tid,NULL,thread,NULL);
sleep(1);
printf("after thread creation\n");
return 0;
}

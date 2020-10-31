#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int count=0;
int add(int a, int b)
{
return a+b;
}
void *thread(void *arg)
{
count++;
printf("in thread: sum is %d\n",add(5,5));
printf("in thread: count is %d",count);
}
int main()
{
pthread_t tid;
printf("in main: count is %d",count);
printf("in main: sum is %d\n",add(10,10));
printf("before thread\n");
pthread_create(&tid,NULL,thread,NULL);
printf("after thread\n");
//sleep(1);
return 0;
}

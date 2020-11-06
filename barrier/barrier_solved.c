#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

 pthread_barrier_t barr;
void *thread_a(void *arg)
{
printf("a: thread initialisation started\n");
sleep(2);
printf("a: thread intialised\n");
pthread_barrier_wait(&barr);
printf("a: started\n");

}

void *thread_b(void *arg)
{
printf("b: thread initialisation started\n");
sleep(10);
printf("b: thread initialised\n");
pthread_barrier_wait(&barr);
printf("b :started\n");
}

void *thread_c(void *arg)
{
printf("c: thread initialisation started\n");
sleep(5);
printf("c: thread intialised\n");
pthread_barrier_wait(&barr);
printf("c :started\n");
}

void *thread_d(void *arg)
{
printf("d: thread initialisation started\n");
sleep(8);
printf("d: thread initialised\n");
pthread_barrier_wait(&barr);
printf("d :started\n");

}


int main()
{
pthread_t a,b,c,d;
pthread_barrier_init(&barr,NULL,4);

pthread_create(&a,NULL,thread_a,NULL);
pthread_create(&b,NULL,thread_b,NULL);
pthread_create(&c,NULL,thread_c,NULL);
pthread_create(&d,NULL,thread_d,NULL);

pthread_join(a,NULL);
pthread_join(b,NULL);
pthread_join(c,NULL);
pthread_join(d,NULL);
 
pthread_barrier_destroy(&barr);

return 0;


}



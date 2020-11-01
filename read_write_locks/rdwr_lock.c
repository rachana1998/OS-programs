#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_rwlock_t rw_count;
int count=4;

void *thread1(void *arg)
{
pthread_rwlock_wrlock(&rw_count);  //write lock
count++;
//printf("T1:count is %d \n",count);
pthread_rwlock_unlock(&rw_count);
}

void *thread2(void *arg)
{
pthread_rwlock_rdlock(&rw_count); //read lock
printf("T2: count is %d\n",count);
pthread_rwlock_unlock(&rw_count);
}

void *thread3(void *arg)
{
pthread_rwlock_rdlock(&rw_count);  //read lock
printf("T3: count is %d\n",count);
pthread_rwlock_unlock(&rw_count);
}

void *thread4(void *arg)
{
pthread_rwlock_wrlock(&rw_count);  
count =count+2;
printf("T4: count is %d\n",count);
pthread_rwlock_unlock(&rw_count);
}


int main()
{
pthread_t tid1,tid2,tid3,tid4;
pthread_rwlock_init(&rw_count,NULL);
pthread_create(&tid1,NULL,thread1,NULL);
pthread_create(&tid2,NULL,thread2,NULL);
pthread_create(&tid3,NULL,thread3,NULL);
pthread_create(&tid4,NULL,thread4,NULL);

pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
pthread_join(tid3,NULL);
pthread_join(tid4,NULL);

pthread_rwlock_destroy(&rw_count);

return 0;
}

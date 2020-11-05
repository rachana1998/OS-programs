#include<stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>       
#include <fcntl.h>  
 #include <sys/mman.h>
 #include<unistd.h>
 #include<sys/types.h>
        

int *count_receiver;
int main()
{
int shfd;

shfd = shm_open("/shared_memory", O_RDWR | O_CREAT , S_IRUSR | S_IWUSR);

ftruncate(shfd,sizeof(int));

count_receiver = (int *)mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE ,  MAP_SHARED, shfd ,0);

while(1)
{
printf("count in receiver %d\n",*count_receiver);
sleep(1);
}

shm_unlink("/shared_memory");

return 0;
}


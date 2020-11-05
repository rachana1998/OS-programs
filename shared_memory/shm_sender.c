#include<stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>       
#include <fcntl.h>  
#include <sys/mman.h>
#include<sys/types.h>
#include<unistd.h>
        

int *count_sender;
int input;
int main()
{
int shfd;

shfd = shm_open("/shared_memory", O_RDWR | O_CREAT , S_IRUSR | S_IWUSR);

ftruncate(shfd,sizeof(int));

count_sender = (int *) mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE , MAP_SHARED, shfd ,0);

while(1)
{
scanf("%d\n",&input);
*count_sender = input;
}

shm_unlink("/shared_memory");
return 0;
}


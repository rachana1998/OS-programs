#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
int fd;
unsigned char rbuff[50];
mkfifo("desd",S_IRUSR | S_IWUSR);
fd=open("desd",O_RDONLY);
read(fd,rbuff,50);
printf("data received from sender is %s\n",rbuff);
close(fd);
return 0;
}

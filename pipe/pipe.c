#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
pid_t id;
int pfd[2];
unsigned char rbuff[20];
pipe(pfd);

id=fork();
if(id==0)
{
read(pfd[0], rbuff,20);
printf("the data received from parent is %s\n",rbuff);

}
else
{
write(pfd[1] ,"cdac",4);
close(pfd[1]);
}
return 0;
}


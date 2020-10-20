#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
pid_t id;
id =fork();
if(id==0)
{
printf("child process pid and ppid is %d %d\n",getpid(),getppid());
}
else
{
printf("parent process pid and ppid is %d %d\n",getpid(),getppid());
}
return 0;
}


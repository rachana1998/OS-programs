#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
pid_t pid;
pid_t ppid;
pid=getpid();
ppid=getppid();
printf("process id is %d\n",pid);
printf("parent process id is %d\n",ppid);
return 0;
}

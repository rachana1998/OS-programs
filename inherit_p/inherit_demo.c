#include<stdio.h>
#include<unistd.h>
int main()
{
pid_t id;

id=fork();

if(id==0)
{
printf("child starting\n");
sleep(10); //child can be inherited by other processes
printf("child exiting\n");
}
else
{
printf("parent starting\n");
sleep(2); //exiting very soon
printf("parent exiting\n");
}
return 0;
}

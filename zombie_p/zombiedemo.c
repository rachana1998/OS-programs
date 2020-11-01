#include<stdio.h>
#include<unistd.h>
int main()
{
pid_t id;

id=fork();

if(id==0)
{
printf("child starting\n");
sleep(2); //exits very soon and this child will go in special state that is zombie state
printf("child exiting\n");
}
else
{
printf("parent starting\n");
sleep(12);
printf("parent exiting\n");
}
return 0;
}

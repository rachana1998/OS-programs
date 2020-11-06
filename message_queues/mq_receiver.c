#include<stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
int main()
{
mqd_t mqfd;
struct mq_attr cdacmq_attr;
char buff[128];
int prio;

 cdacmq_attr.mq_flags = 0;
 cdacmq_attr.mq_maxmsg = 4;
 cdacmq_attr.mq_msgsize= 128;
 cdacmq_attr.mq_curmsgs = 0;
 
mqfd = mq_open("/message_queue", O_RDONLY | O_CREAT, S_IRUSR ,cdacmq_attr);
 
mq_receive(mqfd, buff, 128, &prio);

printf("received: %s\n", buff);

 mq_close(mqfd);
 return 0;
 } 



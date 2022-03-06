#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

#include<mqueue.h>


int main(void)
{
	char buffer[1024];
	bzero(buffer,sizeof(buffer));
	mqd_t fd;

	fd =mq_open("lrt",O_RDWR);

	struct mq_attr attr;
	mq_getattr(fd,&attr);

	printf("%ld\n,%ld\n,%ld\n,%ld\n",attr.mq_flags,attr.mq_maxmsg,attr.mq_msgsize,attr.mq_curmsgs);
	mq_receive(fd,buffer,0x10000,NULL);
	
	printf("receive success message = %s\n",buffer);

	mq_unlink("lrt");

	printf("unlink success\n");

	return 0;
}

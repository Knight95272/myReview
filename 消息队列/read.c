#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>


#include<mqueue.h>


int main(void)
{
	char buffer[1024];
	bzero(buffer,sizeof(buffer));
	mqd_t fd;
	//打开消息队列
	fd = open("myqueue",O_RDWR);
	//接受第一条消息
	/*
	mq_receive (1.mqd_t,
				2.buffer
				3.msg_len 消息队列的长度必须大于msgsize ,否则报错 EMSGSIZE
				4.msg_prio:如果传NULL,表示不设置读取优先级，从较早的消息读取
				)
	*/
	mq_receive(fd,buffer,sizeof(buffer),NULL);

	printf("client receive message = %s\n",buffer);

	mq_close(fd);

	//删除消息队列实体

	mq_unlink("myqueue");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

#include<mqueue.h>

#define MSG "first message..."

int main(void)
{
	mqd_t fd;
	//创建消息队列
	//mq_open(1.name 消息队列名称标记，用户打开或者创建，
	//        2.flag 选项
	//        3.mode 权限掩码
	//        4.mq_attr 创建消息队列时，自定义消息队列属性)
	fd = mq_open("myqueue",O_RDWR|O_CREAT,0664,NULL);
	//发送一条消息
	/*
		mq_send(1. mqd_t  消息队列描述
				2. msg 消息内容
				3. msg_len 消息长度必须小于等于属性中的msgsize,否则报错EMSGSIZE)
			    4. msg_prio 消息优先级，可以给不同的消息设置优先级，读取时按优先级从高到低读取，
				如果不需要设置优先级，可以设0
	*/
	mq_send(fd,MSG,strlen(MSG),0);
	
	printf("send client MSG success\n");
	mq_close(fd);

	return 0;
}

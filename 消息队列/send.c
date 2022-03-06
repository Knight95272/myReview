#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

#include<mqueue.h>

#define MSG "first message.."

int main(void)
{
	mqd_t fd;
	//创建消息队列
	struct mq_attr newattr;
	newattr.mq_flags = 0; //消息标记 O_NONBLOCK 非阻塞消息队列
	newattr.mq_maxmsg = 4096; //消息队列最大消息数
	newattr.mq_msgsize = 8196; // 消息大小
	newattr.mq_curmsgs = 0; // 当前消息数量
	fd = mq_open("/lrt",O_RDWR|O_CREAT,0664,&newattr);
	struct mq_attr attr;
	mq_getattr(fd,&attr);
	//mq_getattr 获取现有消息队列属性
	printf("%ld\n,%ld\n,%ld\n,%ld\n",attr.mq_flags,attr.mq_maxmsg,attr.mq_msgsize,attr.mq_curmsgs);

	//发送消息
	mq_send(fd,MSG,strlen(MSG),0);
	printf("send success...\n");

	//mq_close(fd);

	mq_unlink("lrt");
	return 0;
}

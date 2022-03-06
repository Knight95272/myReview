#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include<time.h>

//守护进程核心工作
int deamon_jobs(void)
{
	char tbuf[1024];
	bzero(tbuf,sizeof(tbuf));
	int fd;
	fd = open("timer.log",O_RDWR|O_CREAT,0664);

	time_t tp;
	while(1)
	{
		tp = time(NULL);
		ctime_r(&tp,tbuf); //将时间种子转换为系统字符串时间

		write(fd,tbuf,sizeof(tbuf));

		bzero(tbuf,sizeof(tbuf));

		sleep(3);

	}
}

//创建守护进程
int create_deamon(void)
{
	//创建父子进程，退出父进程
	pid_t pid;
	pid = fork();

	if(pid > 0){
		exit(-1);
	}else if(pid == 0){
		//2.脱出终端，成立新会话
		setsid();
		//3.关闭无用描述符
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		//4.修改进程工作路径
		chdir("./");
		//5.修改umask掩码
		umask(0002);
		//6.守护进程任务
		deamon_jobs();
		//7.退出处理，释放回收资源


	}else{
		perror("fork call error\n");
		exit(-1);
	}

	
}
//主接口调用关系
int main(void)
{
	
	create_deamon();
	return 0;
}

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#define MSG "hello ,i m parent"

//单工传输
int main(void)
{
	int fds[2];
	pipe(fds);//管道创建

	pid_t pid;
	pid = fork();

	//确定父子间进程的传输方向 ：父写子读
	if(pid > 0){
		close(fds[0]);//关闭管道读端
		printf("parent process pid %d send message \n", getpid());
		write(fds[1],MSG,strlen(MSG));
		close(fds[1]);
		wait(NULL);
	}else if(pid == 0){
		close(fds[1]);//关闭管道写端
		char buffer[1024];
		int rsize;
		bzero(buffer,sizeof(buffer));
		rsize = read(fds[0],buffer,sizeof(buffer));
		printf("son process pid %d ,parent pid %d,read data %s\n",getpid(),getppid(),buffer);
		close(fds[0]);
	}else{
		perror("fork call error");
		exit(-1);
	}
	return 0;
}

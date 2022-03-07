#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<signal.h>


// 用户习惯  kill -9 进程pid
int main(int argc ,char ** argv)
{
	//kill (进程pid ， 信号)  向任意线程发送任意信号
	if(argc <3 )
	{
		printf("请输入正确的参数 三个。\n");
		exit(-1);
	}
	
	kill(atoi(argv[2]),atoi(argv[1]));
	return 0;
}


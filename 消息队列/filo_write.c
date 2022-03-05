#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

#define MSG "hello"

int main()
{
	int wfd;
	mkfifo("makefile",0664);
	wfd = open("makefile",O_WRONLY);
	printf("已走到write\n");
	write(wfd , MSG , sizeof(MSG) );

	close(wfd);

	return 0;
}


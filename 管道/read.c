#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>



int main()
{
	int rfd;
	char buffer[1024];
	int rsize;
	
	bzero(buffer,sizeof(buffer));

	rfd = open("makefile",O_RDONLY);

	rsize = read(rfd ,buffer, sizeof(buffer) );

	printf("所读的数据 ：%s\n",buffer);

	close(rfd);

	return 0;
}


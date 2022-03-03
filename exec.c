#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>



int main(void)
{

 	pid_t pid;
	pid = fork();

	if(pid > 0){
		printf("process pid %d\n",getpid());
		while(1)
			sleep(1);
	}else if(pid == 0){
		printf("son process pid %d \n",getpid());
		execl("/usr/bin/firefox","firefox","https://www.bilibili.com/",NULL);
		printf("successfully\n");
	}else{
		perror("process error");
		exit(-1);
	}



	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(void)
{
 	pid_t pid;
	pid = fork();


	if(pid > 0){
		printf("parent pid %d , pgid %d ,sid %d \n",getpid(),getpgrp(),getsid(getpid()));
		while(1)
			sleep(1);
	}else if(pid == 0){
		printf("child pid %d ,pgid %d ,sid %d \n ",getpid(),getpgrp(),getsid(getpid()));
		printf("child creat group sid \n");
		setsid();
		printf("child pid %d,pgid %d ,sid %d \n ",getpid(),getpgrp(),getsid(getpid()));
		while(1)
			sleep(1);
	}else{
		perror("fork call error\n");
		exit(-1);
	}

	return 0;
}

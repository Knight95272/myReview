

//通过setpgid 可以创建一个新的进程组，也可以将某个组员转到别的进程组中
//父进程默认为组长进程，无法创建进程组
//getpgrp(void) 获取组id

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

//无论组关系怎么变化，亲缘关系不会变化
int main(void)
{
	pid_t pid;
	pid = fork();

	if(pid > 0){
		printf("parent pid %d , pgid %d\n",getpid(),getpgrp() );
		while(1)
			sleep(1);
	}else if(pid == 0){
		printf("child pid %d,pgid %d\n",getpid(),getpgrp());
		printf("child create group \n");
		setpgid(getpid(),getpid());		
		printf("child pid %d,pgid %d\n",getpid(),getpgrp());
		while(1)
			sleep(1);
	}else{
		perror("fork call failed..");
		exit(-1);
	}

	

	return 0;
}

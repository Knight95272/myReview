#include"procopy.h"


int procreate(const char * SFile,const char * DFile,int pronum,int blocksize)
{
	int flag;
	pid_t pid;

	int pos;
	char cblock[100];
	char cpos[100];
	bzero(cblock,sizeof(cblock));
	bzero(cpos,sizeof(cpos));


	for(flag=0;flag<pronum;flag++)
	{
		pid = fork();
		if(pid == 0)
			break;
		
	}
	if(pid > 0){
		printf("parent process pid %d , 非阻塞回收\n",getpid());
		pid_t zpid;
		while((zpid = waitpid(-1,NULL,WNOHANG))!=-1)
		{
			if(pid > 0)
			{
				printf("parent wait sucessfully :zombie pid %d\n",zpid);
			}
		}

	}else if(pid == 0){
		//偏移量的计算  execl重载
		pos = flag * blocksize;
		sprintf(cblock,"%d",blocksize);
		sprintf(cpos,"%d",pos);

		execl("/home/colin/colinsoft/process/0301/demo/Copy","./Copy",SFile,DFile,cblock,cpos,NULL);

	}else{
		perror("fork call error\n");
		exit(-1);
	}

	return 0;
}

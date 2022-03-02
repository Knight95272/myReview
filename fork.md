# Fork 版本，父子进程
```c
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


int main(void)
{
	pid_t pid;
	pid = fork();
	//创建父子进程，子进程的pid是父进程的pid加一
	printf("test message01..\n");
	printf("test message02..\n");

	while(1);
	return 0;

}
```
**
子进程也走fork
调用俩次返回俩次
父子进程fork的返回值不同，父进程返回的是子进程的cpid  > 0
子进程返回的是0，并没有创建和克隆
父进程返回子进程pid ,子进程返回0，创建失败返回-1
子进程并没有创建用户空间和克隆用户空间只有返回值
**
```c
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


int main(void)
{
	pid_t pid;
	pid = fork();
	//通过pid的值来区分父子进程
	if(pid > 0){
		//父进程任务区
		printf("parent process..\n");
	}else if(pid == 0){
		//子进程任务区
		printf("child process..\n");//当前存在子进程会踏出任务区需修改
		//添加部分
		exit(0);
	}else{
		//fork 错误
		perror("fork call error\n");
		exit(-1);

	}
	printf("shared work..\n");


	return 0;
}
```
## 一父多子循环创建
```c
int main(void)
{
	pid_t pid;
	int flag;
	for(flag = 0;flag < 5;flag++){
		pid = fork();
		if(pid == 0){  //父进程才能循环fork，子进程不行，否则会有n层父子进程
			break;
		}
	}
	if(pid > 0){

                printf("parent process..\n");
		while(1)
			sleep(1);
        }else if(pid == 0){
                printf("child process flag[%d]..\n",flag);
		//可见，子进程任务一样当前，可用flag （相当于子进程编号）if else 区分
		if(flag == 0 ){
			printf("cprocess[%d]\n",flag);
		}
		while(1)
                        sleep(1);
        }else{
                //fork 错误
                perror("fork call error\n");
                exit(-1);

        }

	return 0;
}
```
## getid() 与 getppid()
getppid 可以返回调用进程的父进程的pid pid_t pid = getppid(void)
getpid 可以返回调用进程pid 自身 pid_t pid =getpid(void)
```c
int main(void)
{
        pid_t pid;
        int flag;
        for(flag = 0;flag < 5;flag++){
                pid = fork();
                if(pid == 0){  //父进程才能循环fork，子进程不行，否则会有n层父
子进程
                        break;
                }
        }
        if(pid > 0){

                printf("parent pid[%d],ppid[%d] ..\n",getpid(),getppid());
		//结果可见 父进程是bash终端fork出来的
                while(1)
                        sleep(1);
        }else if(pid == 0){
                printf("child pid[%d],ppid[%d]\n",getpid(),getppid());
                while(1)
                        sleep(1);
        }else{
                //fork 错误
                perror("fork call error\n");
                exit(-1);

        }

        return 0;
}


```



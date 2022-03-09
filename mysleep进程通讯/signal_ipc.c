#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>



void sig_parent(int n,siginfo_t *info,void * arg )
{
	union sigval val;
	printf("parent pid %d , count %d\n",getpid(),info->si_int);
	val.sival_int = ++(info->si_int);
	sigqueue(getpid()+1,SIGUSR1,val);
	usleep(5000);//微秒

}
void sig_child(int n,siginfo_t *info,void * arg )
{
	union sigval val;
	printf("child pid %d , count %d\n",getpid(),info->si_int);
	val.sival_int = ++(info->si_int);
	sigqueue(getppid(),SIGUSR2,val);//注意是getppid,向父进程发
	usleep(5000);//微秒

}
int main(void)
{
	sigset_t nset,oset;
	sigemptyset(&nset);
	sigaddset(&nset,SIGUSR1);
	sigprocmask(SIG_SETMASK,&nset,&oset);

	pid_t pid;
	pid = fork();

	if(pid > 0){
		struct sigaction nact,oact;
		nact.sa_sigaction = sig_parent;
		nact.sa_flags = SA_SIGINFO;
		sigemptyset(&nact.sa_mask);
		sigaction(SIGUSR2,&nact,&oact);//捕捉到SIGUSR2信号则发信号
		//第一次信号发送
		union sigval val;
		val.sival_int = 1;
		sigqueue(pid ,SIGUSR1,val);

		while(1)
			sleep(1);
	}else if(pid == 0){
		//捕捉设定
		struct sigaction nact,oact;
		nact.sa_sigaction = sig_child;
		nact.sa_flags = SA_SIGINFO;
		sigemptyset(&nact.sa_mask);
		sigaction(SIGUSR1,&nact,&oact);//捕捉到SIGUSR1信号则发信号
		sigprocmask(SIG_SETMASK,&nact.sa_mask,NULL);//解除屏蔽

		while(1)
			sleep(1);
	}else{
		perror("fork call error \n");
		exit(-1);
	}
	return 0;
}

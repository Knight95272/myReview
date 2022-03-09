#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>


//信号引起的时序竟态

void sig_action(int n)
{
	//捕捉函数空调用
}

unsigned int mysleep(unsigned int n)
{
	sigset_t nset1,oset1;
	sigemptyset(&nset1);
	sigaddset(&nset1,SIGALRM);
	sigprocmask(SIG_SETMASK,&nset1,&oset1);


	unsigned int revalue;
	struct sigaction nact,oact;
	nact.sa_handler = sig_action;
	nact.sa_flags = 0;
	sigemptyset(&nact.sa_mask);
	sigaction(SIGALRM,&nact,&oact);

	revalue = alarm(n);
	sleep(3);

	sigsuspend(&nact.sa_mask);

	return revalue;

}

int main()
{
	while(1)
	{
		printf("one second...\n");
		mysleep(1);

	}
	return 0;


}

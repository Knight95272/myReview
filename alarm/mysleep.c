#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>




void sig_action(int n)
{
	//捕捉函数空调用
}

unsigned int mysleep(unsigned int n)
{
	unsigned int revalue;
	struct sigaction nset,oset;
	nset.sa_handler = sig_action;
	nset.sa_flags = 0;
	sigemptyset(&nset.sa_mask);
	sigaction(SIGALRM,&nset,&oset);

	revalue = alarm(n);

	pause();

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

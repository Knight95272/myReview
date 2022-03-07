#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

void sig_eat(int n)
{
	int flags = 3;
	while(flags)
	{
		printf("\t\t\t\t\t 指令执行%d 次\n",flags--);
		sleep(1);

	}
}


int main(void)
{
	struct sigaction nact,oact;
	nact.sa_handler = sig_eat;
	nact.sa_flags = 0;
	sigemptyset(&nact.sa_mask);
	sigaction(SIGINT,&nact,&oact);

	while(1)
		sleep(1);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

void sig_eat(int n)
{
	printf("eating...\n");
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

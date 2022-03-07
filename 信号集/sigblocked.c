#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<signal.h>

void print_pset(sigset_t pset)
{
	int value;
	int i = 1;
	for(i;i<32;i++)
	{
		if((value = sigismember(&pset, i))==1)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}

	}
	printf("\n");
	
	
}

int main(void)
{
	sigset_t nset,oset;
	sigset_t bset;

	sigemptyset(&nset);
	sigaddset(&nset,SIGINT);
	sigaddset(&nset,SIGQUIT);

	sigprocmask(SIG_SETMASK,&nset,&oset);


	while(1)
	{
		sigpending(&bset);
		print_pset(bset);
		sleep(1);
	
	}



	return 0;
}

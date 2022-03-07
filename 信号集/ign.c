#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#include<signal.h>

int main(void)
{
	struct sigaction nset,oset;
	nset.sa_handler = SIG_IGN;
	nset.sa_flags = 0;
	sigemptyset(&nset.sa_mask);

	sigaction(SIGINT,&nset,&oset);

	printf("修改信号成功\n");

	while(1)
		sleep(1);


	return 0;
}

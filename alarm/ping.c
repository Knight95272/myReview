#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>



int main(void)
{
	struct sigaction nact,oact;
	nact.sa_handler = SIG_IGN;
	nact.sa_flags = 0;
	sigemptyset(&nact.sa_mask);

	sigaction(SIGKILL,&nact,&oact);
	sigaction(SIGINT,&nact,&oact);
	sigaction(SIGQUIT,&nact,&oact);


	printf("修改信号成功\n");
	while(1)
		sleep(1);
	return 0;
}

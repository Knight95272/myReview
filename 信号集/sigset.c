#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<signal.h>

int main(void)
{
	sigset_t nset,oset; //创建信号集

	sigemptyset(&nset); //置空

	sigaddset(&nset,SIGINT); //设置对应信号为1,当前设置屏蔽二号信号，即ctrl +c 不管用

	sigprocmask(SIG_SETMASK,&nset,&oset); //覆盖，将nset覆盖oset

	while(1)
		sleep(1);	

	return 0;
}

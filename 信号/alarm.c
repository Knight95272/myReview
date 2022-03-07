#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>



int main(void)
{
	int sum = 0;


	unsigned int reval;

	reval = alarm(1);


	while(1)
	{
		printf("sum :%d \n",sum++);

	}
	return 0;


}

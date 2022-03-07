#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


int main(void)
{
	char * string = "hell";
	string[0] = 'H';
	printf("%s\n",string);
	
	return 0;
}


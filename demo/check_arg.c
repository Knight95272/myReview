#include "procopy.h"




int check_arg(const char * SFile,int arg_num,int pronum)
{
	//源文件是否存在 参数数量是否满足 进程数量是否溢出
	if(access(SFile,F_OK)!=0)
	{
		perror("check arg error\n");
		exit(-1);
	}
	if(arg_num < 3)
	{
		perror("check arg error : 参数数量量不满足（三个）\n");
	}
	if(pronum <= 0|| pronum >=100)
	{
		perror("check arg error : 进程个数大于0 ，小于100\n");
	}

	return 0;
}

#include "procopy.h"



int main(int argc,char ** argv)
{
	int pronum;
	int blocksize;
	if(argv[3] == 0){
		//设置子线程的缺省值
		pronum = 5;
	}else{
		pronum = atoi(argv[3]);
	}
	
	// 参数检验 线程处理的任务大小 创建子线程
	check_arg(argv[1],argc,pronum);
	blocksize = block(argv[1],pronum);
	procreate(argv[1],argv[2],pronum,blocksize);

	return 0;
}

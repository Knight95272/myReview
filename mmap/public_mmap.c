#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

#include<sys/mman.h> //映射文件主要头文件

int main(void)
{
	//打开映射文件 open ("文件名“，权限--O_RDWR)
	int mfd = open("map_files",O_RDWR);

	//获取文件大小 lseek(文件描述符，偏移的开始位置，结束位置)
	int rsize;
	rsize = lseek(mfd,0,SEEK_END);

	//共享映射
	int * ptr;//ptr 若成功返回，则是映射内存的地址
	ptr = mmap(NULL,rsize,PROT_READ|PROT_WRITE,MAP_SHARED,mfd,0);
	close(mfd);
	
	//change成1234
	ptr[0] = 0x34333231;
	printf("changed success.. \n");

	munmap(ptr,rsize);//释放内存
	return 0;
}

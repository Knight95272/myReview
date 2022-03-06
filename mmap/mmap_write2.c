#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include<sys/mman.h>

//对映射文件进行共享映射，映射成功后修改映射内存，实现同步修改映射文件

int main(void)
{
	int fd = open("Map_files",O_RDONLY);

	int rsize;
	rsize = lseek(fd,0,SEEK_END);

	int * ptr = NULL;
	if((ptr = mmap(NULL,rsize,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0))==MAP_FAILED)
	{
		perror("ptr error\n");
		exit(-1);
	}

	close(fd);


	ptr[0]=0x34333231;
	printf("change success\n");
	munmap(ptr,rsize);



	return 0;
}


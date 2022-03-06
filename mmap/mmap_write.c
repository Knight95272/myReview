#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#include<sys/mman.h>

typedef struct 
{
	char Game_Name[100];
	int Game_Price;
}Game_t;

int main(void)
{
	//创建映射文件
	int fd = open("Map_files",O_RDWR|O_CREAT,0664);
	//映射文件拓展，截断方式为fturncate(文件描述符，大小)
	ftruncate(fd,sizeof(Game_t)); //文件拓展为结构体大小
	//映射
	Game_t * ptr = NULL;
	ptr = mmap(NULL,sizeof(Game_t),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	close(fd);

	bzero(ptr->Game_Name,100);
	ptr->Game_Price = 100;

	while(1)
	{
		sprintf(ptr->Game_Name,"PUBG %d",ptr->Game_Price);
		++(ptr->Game_Price);
		sleep(1);
	}

	munmap(ptr,sizeof(Game_t));



	return 0;
}


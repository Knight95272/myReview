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
	//映射
	Game_t * ptr = NULL;
	ptr = mmap(NULL,sizeof(Game_t),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	close(fd);


	while(1)
	{
		printf("read Client %s,%d\n",ptr->Game_Name,ptr->Game_Price);
		sleep(1);
	}

	munmap(ptr,sizeof(Game_t));



	return 0;
}


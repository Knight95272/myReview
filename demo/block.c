#include "procopy.h"




int block(const char * SFile ,int pronum)
{
	int filesize;
	int fd = open(SFile,0,O_RDONLY);
	//获取文件大小
	filesize = lseek(fd,0,SEEK_END);
	
	if(filesize%pronum == 0){
		return filesize/pronum;
	}else{
		return filesize/pronum + 1;
	}
}

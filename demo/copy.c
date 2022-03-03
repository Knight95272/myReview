#include "procopy.h"



int main(int argc,char ** argv)
{
	// argv1=sfile argv2=dfile argv3=blocksize argv4=pos
	int pos = atoi(argv[4]);
	int blocksize = atoi(argv[3]);
	char buffer[blocksize];
	bzero(buffer,sizeof(buffer));

	
	int rfd = open(argv[1],O_RDONLY);
	int wfd = open(argv[2],O_WRONLY|O_CREAT);

	lseek(rfd,pos,SEEK_SET);
	lseek(wfd,pos,SEEK_SET);

	int rsize;
	rsize = read(rfd,buffer,sizeof(buffer));//从源文件读取buffer大小
	write(wfd,buffer,rsize);

	return 0;
}

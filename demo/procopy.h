#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>


int block(const char * SFile,int pronum); //任务量计算
int check_arg(const char * SFile,int arg_number,int pronum); //参数检查
int procreate(const char *SFile,const char *DFile,int pronum,int blocksize);//创建线程


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
int main(int argc, char** c)
{
    if(argc!=2)
        return 1;
    int file=0;
    if((file=open(c[1],O_RDONLY)) < -1)
    {
        return 1;
    }
    struct stat fileStat;
    if((fstat(file,&fileStat))<0)
        return 1;
    printf("information for %s\n", c[1]);
    printf("filesize%d \n" ,fileStat.st_size);
    printf("time of last access%s \n",ctime(&fileStat.st_atime));
    printf("Owner ID%d \n" ,fileStat.st_uid);
    printf("group ID%d \n",fileStat.st_gid);
}
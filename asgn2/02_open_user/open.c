#include "header.h"


int main(int argc, char *argv[])
{
    int fd = -1, mode = -1;
    if(argc != 3)
    {
        printf("ERROR: Insufficient arguements in make file at line no. 02\n\n");
        return -1;
    }
    
    if(strcmp(argv[2],"read")==0)
    {
         fd = open(argv[1],O_RDONLY);
        printf("inside read");
    }
    if(strcmp(argv[2],"write")==0)
    {
        fd = open(argv[1],O_WRONLY);
        printf("inide write");
    }
    if(strcmp(argv[2],"append")==0)
    {
         fd = open(argv[1],O_APPEND);
        printf("inside append");
    }

    if(fd == -1)
    {
        printf("ERROR: Unable to open File in %s mode \n\n",argv[2]);
    }
    else
    {
        printf("File is successfully opened with file descriptor %d in %s mode\n",fd,argv[2]);
    }
    
    return 0;
    
}

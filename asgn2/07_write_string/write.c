#include "header.h"


int main(int argc, char *argv[])
{
    int fd = 0, ret = 0;
    char localBuffer[512];
    if(argc != 3)
    {
        printf("Insufficient arguements\n\n");
        return -1;
    }
    
    fd = open(argv[1],O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open File\n\n");
    }
    else
    {
        printf("File is successfully opened with file descriptor %d \n",fd);
    }
    
    printf("\n user string : %s ",argv[2]);
    
    int size = strlen(argv[2]);
     printf("\n size  : %d \n",size);
    ret = write(fd,argv[2],sizeof(argv[2]));
    
    if(ret != sizeof(argv[2]))
    {
        printf("Unable to write contents\n");
    }
    
    lseek(fd,0,SEEK_SET);
    printf("\n Data from file :");
    memset(localBuffer,0,0);
    while((read(fd,localBuffer,sizeof(localBuffer))!=0))
    {
        printf("\n %s ",localBuffer);
    }
 
    printf("\n \n");
    return 0;
    
}

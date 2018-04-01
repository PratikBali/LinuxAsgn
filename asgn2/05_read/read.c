#include "header.h"


int main(int argc, char *argv[])
{
    int fd = 0, ret = 0, size = 0;
    char localBuffer[5];
    if(argc != 3)
    {
        printf("Insufficient arguements\n\n");
        return -1;
    }
    
    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open File\n\n");
    }
    else
    {
        printf("File is successfully opened with file descriptor %d \n",fd);
    }
    
    size = atoi(argv[2]);
     printf("\n size : %d\n\n",size);
    ret = read(fd,localBuffer,size);
    
    printf("\n Data from file : %s \n\n",localBuffer);
    
    return 0;
    
}

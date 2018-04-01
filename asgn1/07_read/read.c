#include "header.h"


int main(int argc, char *argv[])
{
    int fd = 0, ret = 0;
    char localBuffer[5];
    if(argc != 2)
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
    
    ret = read(fd,localBuffer,5);
    
    printf("\n Data from file : %s \n\n",localBuffer);
    
    return 0;
    
}

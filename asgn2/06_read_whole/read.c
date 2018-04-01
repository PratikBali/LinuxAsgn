#include "header.h"


int main(int argc, char *argv[])
{
    int fd = 0, ret = 0;
    char localBuffer[512];
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
    
    printf("\n Data from file :");
    while((read(fd,localBuffer,sizeof(localBuffer))!=0))
    {
        printf("\n %s ",localBuffer);
    }
 
    return 0;
    
}

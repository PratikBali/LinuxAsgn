#include "header.h"


int main(int argc, char *argv[])
{
    int fd = 0;
    if(argc != 2)
    {
        printf("Insufficient arguements\n\n");
        return -1;
    }
    
    fd = open("file_to_open.txt",O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open File\n\n");
    }
    else
    {
        printf("File is successfully opened with file descriptor %d \n",fd);
    }
    
    return 0;
    
}

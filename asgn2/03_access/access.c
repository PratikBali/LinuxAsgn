#include "header.h"


int main(int argc, char *argv[])
{
    int fd = 0, mode = -1;
    if(argc != 3)
    {
        printf("ERROR: Insufficient arguements in make file at line no. 02\n\n");
        return -1;
    }

    
    if (access(argv[1],R_OK) < 0)
    {
        printf("Our process can not access this file for reading purpose\n");
    }
    else
    {
        printf("Our process has read access\n");
    }
    
    if (access(argv[1], W_OK) < 0)
    {
        printf("Our process can not access this file for writing purpose\n");
    }
    else
    {
        printf("Our process has write access\n");
    }
    // also check for an execute permission...
    if (access(argv[1], X_OK) < 0)
    {
        printf("Our process can not access this file for executing purpose\n");
    }
    else
    {
        printf("Our process has executing access\n");
    }
    
    return 0;
    
}

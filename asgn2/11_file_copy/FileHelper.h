#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int fd = 0;
int ret = 0, result = 0, count = 0;
char arr[20];

int create(char *name)
{
    
    fd = creat(name,0777);
    
    if(fd == -1)
    {
        printf("\n ERROR: Unable to create the file \n\n");
        return -1;
    }
    
    else
    {
        printf("\n File is successfully created with fd : %d \n",fd);
        return fd;
    }
}
int OpenFile(char *name)
{
    
    fd = open(name,O_RDWR | O_APPEND | O_CREAT );
    
    if(fd == -1)
    {
        printf("\n ERROR: Unable to open the file \n\n");
        return -1;
    }
    
    else
    {
        printf("\n File is successfully opened with fd : %d \n",fd);
        return fd;
    }
}
int OpenFileRDWR(char *name)
{

	fd = open(name,O_RDWR |  O_CREAT);

	if(fd == -1)
	{
		printf("\n ERROR: Unable to open the file \n\n");
        return -1;
	}

	else
	{
        printf("\n File is successfully opened with fd : %d \n",fd);
            return fd;
	}
}

int OpenFileRD(char *name)
{
    
    fd = open(name,O_RDONLY);
    
    if(fd == -1)
    {
        printf("\n ERROR: Unable to open the file \n\n");
        return -1;
    }
    
    else
    {
        printf("\n File is successfully opened with fd : %d \n",fd);
        return fd;
    }
}

int OpenFileWR(char *name)
{
    
    fd = open(name,O_WRONLY |  O_CREAT );
    
    if(fd == -1)
    {
        printf("\n ERROR: Unable to open the file \n\n");
        return -1;
    }
    
    else
    {
        printf("\n File is successfully opened with fd : %d \n",fd);
        return fd;
    }
}

int FileSize(int fd)
{
    if(fd == -1)
    {
        return -1;
    }
    
    while((ret = read(fd,arr,sizeof(arr))) != 0)
    {
        result = result + ret;
    }
    
   // printf("Size : %d \n",result);
    
    return result;
}

void PrintFile(int fd)
{
    printf("\n Your file data :\n ");
    while((ret = read(fd,arr,sizeof(arr))) != 0)
    {
        if(ret < 0)
        {
            printf("\n ret : %d ",ret);
            printf("\nError: Cannot read file");
            return;
        }
        else
        {
            printf("%s",arr);
            memset(arr,0,sizeof(arr));
        }
       
    }
    printf("\n ");
}



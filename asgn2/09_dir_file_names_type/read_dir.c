#include "header.h"

void fileType(char *name)
{
    int  ret = 0;
    struct stat fileStat;
    
    ret = stat(name,&fileStat);
    if(ret == -1)
    {
        printf("stat function fail\n");
        return;
    } 
         
    if(S_ISLNK(fileStat.st_mode))
    {
        printf("Type: symbolic link\n");
    }
    if(S_ISREG(fileStat.st_mode))
    {
        printf("Type: Regular File\n");
    }
    if(S_ISDIR(fileStat.st_mode))
    {
        printf("Type: Directory File\n");
    }
}

int main(int argc, char *argv[])
{
    int fd = 0, ret = 0, size = 0;
    
    char localBuffer[5];
    if(argc != 2)
    {
        printf("Insufficient arguements\n\n");
        return -1;
    }
    
    DIR *dir;
	struct dirent *entry;

	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}

	printf("Files in directory as \n");
	while ((entry = readdir(dir)) != NULL)
	{
	      printf("Name: %s \t", entry->d_name);
          fileType(entry->d_name);
	}
	
	closedir(dir);
    
    return 0;
    
}

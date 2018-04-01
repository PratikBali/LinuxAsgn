#include "header.h"

int main(int argc, char *argv[])
{
    int fd = 0, ret = 0, size = 0, max = 0;
    struct stat fileStat;
    char *name;
    
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
    
	printf("\n Maximum size of File in directory as \n");
	while ((entry = readdir(dir)) != NULL)
	{
        ret = stat((entry->d_name),&fileStat);
        if(ret == -1)
        {
            printf("stat function fail\n");
            return -1;
        } 
        if(max < ((int)fileStat.st_size))
        {
            name = (entry->d_name);
            max = ((int)fileStat.st_size);
        }
    }
    
    printf("Name: %s \t\t", name);
    printf("File Size : \t %d bytes\n",max);
	
	
	closedir(dir);
    
    return 0;
    
}

#include "header.h"


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
	      printf(" %s\n", entry->d_name);
	}
	
	closedir(dir);
    
    return 0;
    
}

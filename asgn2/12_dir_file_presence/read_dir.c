#include "header.h"


int main(int argc, char *argv[])
{
    int fd = 0, ret = 0, flag = 0;
    char localBuffer[5];
    if(argc != 3)
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

	while (((entry = readdir(dir)) != NULL) && flag!= 1)
	{
	     // printf(" %s\n", entry->d_name);
        if(strcmp(argv[2],(entry->d_name)) == 0)
        {
            flag =1;
        }
	}
    
    if(flag==1)
    {
        printf("\n found \n");
    }
    else
    {
        printf("\n not found \n");
    }
	
	closedir(dir);
    
    return 0;
    
}

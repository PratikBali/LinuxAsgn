#include "header.h"
#include "FileHelper.h"

void CopyFile(char *src, char* dest)
{
     //printf("\n bytes : %d ",bytes);
    int srcFD = 0, destFD = 0, ret = 0, ActualSize = 0;
    char *arr;
    
    srcFD = OpenFileRD(src);
    //PrintFile(srcFD);
    destFD = OpenFileWR(dest);
    
    lseek(srcFD,0,0);
    ActualSize = FileSize(srcFD);
    printf("\n ActualSize : %d ",ActualSize);
    
    arr = (char*)malloc(ActualSize);
  
    lseek(srcFD,0,0);
    ret = read(srcFD,arr,ActualSize);
    printf("\n ret : %d ",ret);
    
    if(ret >= 0)
    {
        write(destFD,arr,ret);
        printf("\nWritten");
        //memset(arr,0,strlen(arr));
    }
    else
    {
        
        printf("\nError: Cannot read file");
        return;
    }
}

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("\nInsufficient arguements");
        printf("\n usage : <exename> <source-filename> <dest-filename>\n");

        return -1;
    }
    unlink(argv[2]);
    
    CopyFile(argv[1],argv[2]);
    printf("\n\n");
    
    return 0;
}
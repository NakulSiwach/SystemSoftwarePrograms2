/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdio.h>

void main()
{
    long maxFiles;  
    long sizeOfPipe;

    char *s = "23_fifo";
    mkfifo(s, S_IRWXU);

    maxFiles = sysconf(_SC_OPEN_MAX);

    printf("Maximum number of files that can be opened is: %ld\n", maxFiles);


    printf("Maximum size of pipe: %d\n", PIPE_BUF);
    
}


    
/*

*/
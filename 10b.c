/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 10. Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE

*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void print()
{
    printf("Caught SIGINT\n");
}
void main()
{
    int status;
    struct sigaction act;

    act.sa_handler = print; 
    act.sa_flags = 0;
    status = sigaction(SIGINT, &act, NULL);
    if (status == -1)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        raise(SIGINT);
    }
}
// output 
//  ./a.out 
// Caught SIGINT
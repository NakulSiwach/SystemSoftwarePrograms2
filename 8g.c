/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 8. Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)

*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>


void sigprof_handler(int signal) {
    printf("Caught SIGPROF: Profiling timer expired\n");
}

int main() {
    signal(SIGPROF, sigprof_handler);  

    struct itimerval timer;
    timer.it_value.tv_sec = 2;        
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;     
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);
    int fd = open("dummyfile.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    for (long long i = 0; i < 1e8; ++i) {
        int x = i * i;

        if (write(fd, "data\n", 5) == -1) {
            perror("Write failed");
            return 1;
        }
    }
    close(fd);

    return 0;
}



// output 
// ./a.out 
// Waiting for the virtual timer...
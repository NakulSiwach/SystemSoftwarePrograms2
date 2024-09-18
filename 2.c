/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 2. Write a program to print the system resource limits. Use getrlimit system call.

*/



#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

void print_limits(int resource, const char *name) {
    struct rlimit limit;
    
    // Get the resource limit
    if (getrlimit(resource, &limit) == 0) {
        if (limit.rlim_cur == RLIM_INFINITY)
            printf("%-25s: Soft limit = infinity, ", name);
        else
            printf("%-25s: Soft limit = %llu, ", name, (unsigned long long)limit.rlim_cur);

        if (limit.rlim_max == RLIM_INFINITY)
            printf("Hard limit = infinity\n");
        else
            printf("Hard limit = %llu\n", (unsigned long long)limit.rlim_max);
    } else {
        perror("getrlimit");
    }
}

int main() {
    // Print resource limits
    print_limits(RLIMIT_CPU, "CPU time (seconds)");
    print_limits(RLIMIT_FSIZE, "File size (bytes)");
    print_limits(RLIMIT_DATA, "Data seg size (bytes)");
    print_limits(RLIMIT_STACK, "Stack size (bytes)");
    print_limits(RLIMIT_CORE, "Core file size (bytes)");
    print_limits(RLIMIT_RSS, "Resident set size (bytes)");
    print_limits(RLIMIT_NOFILE, "Number of open files");
    print_limits(RLIMIT_AS, "Address space (bytes)");
    print_limits(RLIMIT_NPROC, "Max number of processes");
    print_limits(RLIMIT_MEMLOCK, "Max locked memory (bytes)");

    return 0;
}

/*

CPU time (seconds)       : Soft limit = infinity, Hard limit = infinity
File size (bytes)        : Soft limit = infinity, Hard limit = infinity
Data seg size (bytes)    : Soft limit = infinity, Hard limit = infinity
Stack size (bytes)       : Soft limit = 8388608, Hard limit = infinity
Core file size (bytes)   : Soft limit = 0, Hard limit = infinity
Resident set size (bytes): Soft limit = infinity, Hard limit = infinity
Number of open files     : Soft limit = 1048576, Hard limit = 1048576
Address space (bytes)    : Soft limit = infinity, Hard limit = infinity
Max number of processes  : Soft limit = 55015, Hard limit = 55015
Max locked memory (bytes): Soft limit = 1812328448, Hard limit = 1812328448

*/
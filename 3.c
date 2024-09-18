/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 3. Write a program to set (any one) system resource limit. Use setrlimit system call.

*/


#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

void print_limits(int resource, const char *name) {
    struct rlimit limit;

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
    struct rlimit new_limit;

    // Display the current limit for open files
    printf("Current limits for open files:\n");
    print_limits(RLIMIT_NOFILE, "Number of open files");

    // Set new limits for RLIMIT_NOFILE (number of file descriptors)
    new_limit.rlim_cur = 1024;  // New soft limit
    new_limit.rlim_max = 2048;  // New hard limit

    if (setrlimit(RLIMIT_NOFILE, &new_limit) != 0) {
        perror("Failed to set new limits");
        return 1;
    }

    // Display the updated limits for open files
    printf("\nUpdated limits for open files:\n");
    print_limits(RLIMIT_NOFILE, "Number of open files");

    return 0;
}


/*

Current limits for open files:
Number of open files     : Soft limit = 1048576, Hard limit = 1048576

Updated limits for open files:
Number of open files     : Soft limit = 1024, Hard limit = 2048

*/
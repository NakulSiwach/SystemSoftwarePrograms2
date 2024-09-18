/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 5. Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.

*/

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    // a. Maximum length of the arguments to the exec family of functions
    long max_arg_length = sysconf(_SC_ARG_MAX);
    if (max_arg_length != -1) {
        printf("Maximum length of arguments to the exec family: %ld\n", max_arg_length);
    } else {
        perror("sysconf(_SC_ARG_MAX) failed");
    }

    // b. Maximum number of simultaneous processes per user id
    long max_processes = sysconf(_SC_CHILD_MAX);
    if (max_processes != -1) {
        printf("Maximum number of simultaneous processes per user: %ld\n", max_processes);
    } else {
        perror("sysconf(_SC_CHILD_MAX) failed");
    }

    // c. Number of clock ticks (jiffy) per second
    long clock_ticks = sysconf(_SC_CLK_TCK);
    if (clock_ticks != -1) {
        printf("Number of clock ticks per second: %ld\n", clock_ticks);
    } else {
        perror("sysconf(_SC_CLK_TCK) failed");
    }

    // d. Maximum number of open files
    long max_open_files = sysconf(_SC_OPEN_MAX);
    if (max_open_files != -1) {
        printf("Maximum number of open files: %ld\n", max_open_files);
    } else {
        perror("sysconf(_SC_OPEN_MAX) failed");
    }

    // e. Size of a page
    long page_size = sysconf(_SC_PAGESIZE);
    if (page_size != -1) {
        printf("Size of a page: %ld bytes\n", page_size);
    } else {
        perror("sysconf(_SC_PAGESIZE) failed");
    }

    // f. Total number of pages in the physical memory
    long total_pages = sysconf(_SC_PHYS_PAGES);
    if (total_pages != -1) {
        printf("Total number of pages in physical memory: %ld\n", total_pages);
    } else {
        perror("sysconf(_SC_PHYS_PAGES) failed");
    }

    // g. Number of currently available pages in the physical memory
    long available_pages = sysconf(_SC_AVPHYS_PAGES);
    if (available_pages != -1) {
        printf("Number of currently available pages in physical memory: %ld\n", available_pages);
    } else {
        perror("sysconf(_SC_AVPHYS_PAGES) failed");
    }

    return 0;
}




/*
Maximum length of arguments to the exec family: 2097152
Maximum number of simultaneous processes per user: 55015
Number of clock ticks per second: 100
Maximum number of open files: 1048576
Size of a page: 4096 bytes
Total number of pages in physical memory: 3539711
Number of currently available pages in physical memory: 2040698
*/
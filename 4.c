/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 4. Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.

*/

#include <stdio.h>
#include <unistd.h>

#if defined(__i386__)
static __inline__ unsigned long long rdtsc(void) {
    unsigned long long int x;
    __asm__ volatile ("rdtsc" : "=A" (x));
    return x;
}
#elif defined(__x86_64__)
static __inline__ unsigned long long rdtsc(void) {
    unsigned hi, lo;
    __asm__ volatile ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)lo) | (((unsigned long long)hi) << 32);
}
#endif

int main() {
    unsigned long long start, end;
    int i;

    // Read the time-stamp counter before making system calls
    start = rdtsc();

    // Perform 100 getppid() system calls
    for (i = 0; i < 100; i++) {
        getppid();
    }

    // Read the time-stamp counter after the system calls
    end = rdtsc();

    // Calculate the number of CPU cycles taken for 100 getppid() calls
    printf("Time taken for 100 getppid() system calls: %llu CPU cycles\n", (end - start));

    return 0;
}




/*
Time taken for 100 getppid() system calls: 82926 CPU cycles
*/
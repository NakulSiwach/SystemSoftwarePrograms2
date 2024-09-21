/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore

*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>    
#include <sys/stat.h> 
#include <unistd.h>   

int main() {
    sem_t *binary_sem = sem_open("/binary_sem", O_CREAT | O_EXCL, 0644, 1);
    if (binary_sem == SEM_FAILED) {
        perror("sem_open (binary)");
        exit(EXIT_FAILURE);
    }
    printf("Binary semaphore created and initialized to 1.\n");

    sem_t *counting_sem = sem_open("/counting_sem", O_CREAT | O_EXCL, 0644, 5);
    if (counting_sem == SEM_FAILED) {
        perror("sem_open (counting)");
        sem_close(binary_sem);
        sem_unlink("/binary_sem");
        exit(EXIT_FAILURE);
    }
    printf("Counting semaphore created and initialized to 5.\n");

    sem_close(binary_sem);
    sem_close(counting_sem);
    sem_unlink("/binary_sem");
    sem_unlink("/counting_sem");

    return 0;
}


    
/*
Binary semaphore created and initialized to 1.
Counting semaphore created and initialized to 5.
*/
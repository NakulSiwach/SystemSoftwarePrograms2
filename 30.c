/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define SHM_SIZE 1024  

int main() {
    int shmid;
    char *data;
    key_t key = 1234; 

    shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    data = (char *)shmat(shmid, NULL, 0); 
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    printf("Writing data to shared memory...\n");
    strncpy(data, "Hello, Shared Memory!", SHM_SIZE);

    printf("Data in shared memory: %s\n", data);

    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    printf("Attaching shared memory in read-only mode...\n");
    data = (char *)shmat(shmid, NULL, SHM_RDONLY); 
    if (data == (char *)(-1)) {
        perror("shmat (read-only)");
        exit(1);
    }

    printf("Data in shared memory (read-only): %s\n", data);

    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    printf("Removing shared memory segment...\n");
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}


    
/*
Writing data to shared memory...
Data in shared memory: Hello, Shared Memory!
Attaching shared memory in read-only mode...
Data in shared memory (read-only): Hello, Shared Memory!
Removing shared memory segment...
*/
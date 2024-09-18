/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 7. Write a simple program to print the created thread ids.

*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Function to be executed by each thread
void* thread_function(void* arg) {
    printf("Thread %ld is running\n", pthread_self());  // Print thread ID
    sleep(1);  // Simulate some work
    return NULL;
}

int main() {
    pthread_t threads[3];  // Array to store thread identifiers

    // Create three threads
    for (int i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            return 1;
        }
    }

    printf("All threads have finished executing\n");
    return 0;
}



/*
Thread 139978206082752 is running
Thread 139978189297344 is running
Thread 139978197690048 is running
All threads have finished executing

*/

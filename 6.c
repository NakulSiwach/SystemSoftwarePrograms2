/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 6. Write a simple program to create three threads.

*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Function to be executed by each thread
void* thread_function(void* arg) {
    int thread_id = *((int*)arg);
    printf("Thread %d is running\n", thread_id);
    sleep(1);  // Simulate some work
    printf("Thread %d has finished\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];   // Array to store thread identifiers
    int thread_ids[3];      // Array to pass thread IDs

    // Create three threads
    for (int i = 0; i < 3; i++) {
        thread_ids[i] = i + 1;  // Assign thread ID (1, 2, 3)
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
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

Thread 2 is running
Thread 1 is running
Thread 3 is running
Thread 2 has finished
Thread 1 has finished
Thread 3 has finished
All threads have finished executing

*/
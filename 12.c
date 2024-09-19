/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process created. PID: %d\n", getpid());

        // Send SIGKILL signal to the parent process
        printf("Child is sending SIGKILL signal to parent process (PID: %d)\n", getppid());
        kill(getppid(), SIGKILL);

        // Parent process should now be killed; the child becomes an orphan
        sleep(5); // Sleep for a while to show that it's now an orphan
        printf("Child process is now an orphan and has been adopted by init/systemd. New parent PID: %d\n", getppid());
    } else {
        // Parent process
        printf("Parent process. PID: %d\n", getpid());
        
        // Sleep for a while to ensure the parent doesn't exit before the child sends the signal
        sleep(10);
    }

    return 0;
}


/*
Parent process. PID: 10652
Child process created. PID: 10653
Child is sending SIGKILL signal to parent process (PID: 10652)
Killed
administrator@administrator-82LN:~/systemsoftwarepracticals/HandsOnList1$ Child process is now an orphan and has been adopted by init/systemd. New parent PID: 1513
*/
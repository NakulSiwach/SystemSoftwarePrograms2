/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 29. Write a program to remove the message queue.

*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main() {
    key_t key;
    int msgid;

    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl - IPC_RMID");
        exit(1);
    }

    printf("Message queue removed successfully.\n");

    return 0;
}
    
/*

*/
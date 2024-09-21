/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 28. Write a program to change the exiting message queue permission. (use msqid_ds structure)

*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds buf;

    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl - IPC_STAT");
        exit(1);
    }

    printf("Current permissions: %o\n", buf.msg_perm.mode);

    buf.msg_perm.mode = 0644;

    if (msgctl(msgid, IPC_SET, &buf) == -1) {
        perror("msgctl - IPC_SET");
        exit(1);
    }

    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl - IPC_STAT");
        exit(1);
    }

    printf("Updated permissions: %o\n", buf.msg_perm.mode);

    return 0;
}

    
/*
Current permissions: 666
Updated permissions: 644
*/
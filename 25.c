/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv

*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() {
    key_t key = ftok(".", 65);  
    int msqid = msgget(key, 0666 | IPC_CREAT);

    if (msqid == -1) {
        perror("msgget");
        return 1;
    }

    struct msqid_ds buf;

    if (msgctl(msqid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("Access permissions: %o\n", buf.msg_perm.mode);

    printf("Owner UID: %d\n", buf.msg_perm.uid);
    printf("Owner GID: %d\n", buf.msg_perm.gid);

    printf("Last msg sent time: %s", ctime(&buf.msg_stime));
    printf("Last msg received time: %s", ctime(&buf.msg_rtime));

    printf("Last change time: %s", ctime(&buf.msg_ctime));

    printf("Current number of bytes in queue: %ld\n", buf.__msg_cbytes);

    printf("Number of messages in queue: %lu\n", buf.msg_qnum);

    printf("Max bytes allowed in queue: %lu\n", buf.msg_qbytes);

    printf("PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}

    
/*
Access permissions: 666
Owner UID: 1000
Owner GID: 1000
Last msg sent time: Thu Jan  1 05:30:00 1970
Last msg received time: Thu Jan  1 05:30:00 1970
Last change time: Sat Sep 21 16:18:53 2024
Current number of bytes in queue: 0
Number of messages in queue: 0
Max bytes allowed in queue: 16384
PID of last msgsnd: 0
PID of last msgrcv: 0
*/
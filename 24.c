/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 24. Write a program to create a message queue and print the key and message queue id.

*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct mesg_buffer
{
    long mesg_type;
    char mesg_text[100];
} mesg_buffer;
int main()
{
    mesg_buffer message;
    key_t key = ftok(".", 1); 
    printf("Key for given path and project id is :%d \n", key);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    printf("Message queue id : %d\n", msgid);
    return 0;
}

    
/*
Key for given path and project id is :17271495 
Message queue id : 0
*/
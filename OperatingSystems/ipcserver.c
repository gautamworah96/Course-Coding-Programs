#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
#define MSGKEY 75 
 
struct msgform 
{ 
    long mtype; 
    char mtext[256]; 
}msg; 
 
int msgid;

cleanup(){ 
    msgctl(msgid,IPC_RMID,0);
    exit(0);
    }
     
 
void main(){ 
     
    int i,pid, *pint; 
    extern cleanup(); 
     
    for(i=0;i<20;i++) 
    signal(i,cleanup); 
    msgid=msgget(MSGKEY,0777|IPC_CREAT); 
    for(;;){ 
        msgrcv(msgid,&msg,256,1,0); 
         
        printf("server: receive from %s\n",msg.mtext); 
        printf("Enter the message:\n"); 
         
        gets(msg.mtext); 
        msg.mtype=1; 
        msgsnd(msgid,&msg,sizeof(char)*256,0); 
    } 
     
}

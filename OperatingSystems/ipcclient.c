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

void main(){
	
	struct msgform msg;
	int msgid;
	
	msgid=msgget(MSGKEY,0777);
	
	for(;;){
		printf("Enter The message:\n");
		gets(msg.mtext);
		msg.mtype=1;
		
		msgsnd(msgid,&msg,sizeof(char)*256,0);
		msgrcv(msgid,&msg,256,1,0);
		printf("Client:receive msg %s\n",msg.mtext);
	}
}

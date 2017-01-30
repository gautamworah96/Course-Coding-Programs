#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#define MAX 200


void childprocess(){
	int i;
	for(i=1;i<=MAX;i++)
	printf("This line is from child value=%d and pid=%d\n",i,getpid());
	printf("**CHILD PROCESS IS DONE**\n");
}
void parentprocess(){
	int i;
	for(i=1;i<=MAX;i++)
	printf("This line is from parent value=%d and ppid=%d\n",i,getppid());
	printf("**PARENT PROCESS IS DONE**\n");
}
void main(){
	pid_t pid;
	pid=fork();
	if(pid==0)
	childprocess();
	else
	parentprocess();
	
}

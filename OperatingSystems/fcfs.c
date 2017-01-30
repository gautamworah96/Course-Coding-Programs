#include<stdio.h>
void main()
{
	int n,i,j,totalTime=0;
	printf("Enter the Number of Processes:- ");
	scanf("%d",&n);
	int arrTime[n],exeTime[n+1],processId[n],endTime[n],executed[n];
	int processExe;
	for(i=0;i<n;i++)
	{
		processId[i]=i+1;
		printf("Enter The Arrival time of Process P%d :-",processId[i]);
		scanf("%d",&arrTime[i]);
		printf("Enter The Execution time of Process P%d :-",processId[i]);
		scanf("%d",&exeTime[i]);
		totalTime+=exeTime[i];
		executed[i]=0;
	}
	exeTime[n]=65536;
	processExe=n+1;
	printf("PROCESS\t\tARRIVAL TIME\tEXECUTION TIME");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t\t%d\t\t%d",processId[i],arrTime[i],exeTime[i]);
	} 
	printf("\nTotal time: %d",totalTime);
	//spn
	i=0;
	while(i<totalTime)
	{
		for(j=0;j<n;j++)
		{
			if(arrTime[j]<=i&&executed[j]==0)
			{
				//addin Process Queue
				if(exeTime[processExe-1]>exeTime[j])
				{
					processExe=processId[j];
				}
			}
		}
		i+=exeTime[processExe-1];
		executed[processExe-1]=1;
		endTime[processExe-1]=i;
		processExe=n+1;
	}
	printf("\nPROCESS\t\tTURNAROUND TIME");
	int tat=0;
	for(i=0;i<n;i++)
	{
		printf("\n%d\t\t%d",processId[i],endTime[i]-arrTime[i]);
		tat+=endTime[i]-arrTime[i];
	}
	printf("\nTotal Turnaround Time:  %d",tat );
	printf("\nAverage Turnaround Time:  %d",tat/n );
}

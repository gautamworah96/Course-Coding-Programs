#include<stdio.h>
int nP,nMB;
void input(int p[],int m[])
{
	int i,j;
	printf("Enter the No of Processes: ");
	scanf("%d",&nP);
	printf("Enter the No of Memory Blocks available: ");
	scanf("%d",&nMB);
	printf("Enter sizes of processes:");
	for(i=0;i<nP;i++)
	{
		scanf("%d",&p[i]);
	}
	printf("Enter sizes of memory blocks:");
	for(i=0;i<nMB;i++)
	{
		scanf("%d",&m[i]);
	}

}
void next(int p[],int m[])
{
	int i,j=0,cycle;
	for(i=0;i<nP;i++)
	{
		cycle=nMB;
		while(cycle>0)
		{
			cycle--;
			if(m[j]>=p[i])
			{
				printf("\nProcess No %d with memory %d has been allotted to memory block %d with memory %d  ",i+1,p[i],j+1,m[j]);
				m[j]-=p[i];
				printf("Remaining Space in Memory block %d\n",m[j]);
				break;
			}
			j++;
			if(j==nMB)
				j=0;
			
		}
		if(cycle==0)
		{
			printf("\nNo Space for process no %d As not enough memory\n",i+1);
		}
	}
}
void best (int p[],int m[])
{
	int i,j;
	for(i=0;i<nP;i++)
	{
		int min=9999;
		int minIndex;
		for(j=0;j<nMB;j++)
		{
			if(min>m[j]&&m[j]>=p[i])
			{
				min=m[j];
				minIndex=j;
			}
		}
		if(min==9999)
		{
			printf("\nNo Space for process no %d As not enough memory\n",i+1);
			continue;
		}
		printf("\nProcess No %d with memory %d has been allotted to memory block %d with memory %d  ",i+1,p[i],minIndex+1,m[minIndex]);
		m[minIndex]-=p[i];
		printf("Remaining Space in Memory block %d\n",m[minIndex]);
	}
}
void first (int p[],int m[])
{
	int i,j;
	for(i=0;i<nP;i++)
	{
		for(j=0;j<nMB;j++)
		{
			if(m[j]>=p[i])
			{
				printf("\nProcess No %d with memory %d has been allotted to memory block %d with memory %d  ",i+1,p[i],j+1,m[j]);
				m[j]-=p[i];
				printf("Remaining Space in Memory block %d\n",m[j]);
				break;
			}
		}
		if(j==nMB)
		{
			printf("\nNo Space for process no %d As not enough memory\n",i+1);
		}
	}
}
void main()
{
	int ch;
	int p[20],m[20];
	printf("\nMENU:\n1.Best Fit\n2.Next Fit\n3.First Fit\n4.Exit\nEnter Your Choice:- ");
	scanf("%d",&ch);
	input(p,m);
	switch(ch)
	{
		case 1:
			best(p,m);
			main();
		break;
		case 2:
			next(p,m);
			main();
		break;
		case 3:
			first(p,m);
			main();
		break;
		case 4:
		break;
		default:
			printf("\nINVALID INPUT!!!!!!\n");
			main();
		
	}
}
/*
MENU:
1.Best Fit
2.Next Fit
3.Exit
Enter Your Choice:- 1
Enter the No of Processes: 4 
Enter the No of Memory Blocks available: 5
Enter sizes of processes:212 417 112 426
Enter sizes of memory blocks:100 500 200 300 600

Process No 1 with memory 212 has been allotted to memory block 4 with memory 300  Remaining Space in Memory block 88

Process No 2 with memory 417 has been allotted to memory block 2 with memory 500  Remaining Space in Memory block 83

Process No 3 with memory 112 has been allotted to memory block 3 with memory 200  Remaining Space in Memory block 88

Process No 4 with memory 426 has been allotted to memory block 5 with memory 600  Remaining Space in Memory block 174

MENU:
1.Best Fit
2.Next Fit
3.Exit
Enter Your Choice:- 2
Enter the No of Processes: 4
Enter the No of Memory Blocks available: 5
Enter sizes of processes:212 417 112 200
Enter sizes of memory blocks:100 500 200 300 600

Process No 1 with memory 212 has been allotted to memory block 2 with memory 500  Remaining Space in Memory block 288

Process No 2 with memory 417 has been allotted to memory block 5 with memory 600  Remaining Space in Memory block 183

Process No 3 with memory 112 has been allotted to memory block 5 with memory 183  Remaining Space in Memory block 71

Process No 4 with memory 200 has been allotted to memory block 2 with memory 288  Remaining Space in Memory block 88

MENU:
1.Best Fit
2.Next Fit
3.Exit
Enter Your Choice:- 3
*/

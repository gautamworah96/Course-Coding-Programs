#include<stdio.h>
#include<math.h>
int arr[30],ser[30],tat[30];
void srtn(int n){
	
	int sum=0,service,i,j,k,l;
	float avg,sum1;
	for(i=0;i<n;i++){
		sum=sum+ser[i];
		tat[i]=0;
	}
	service=20;
	ser[service]=99;
	for(j=0;j<sum;j++){
		if(ser[service]==0)
		{
			service=20;
			for(k=0;k<n;k++)
			{
				if(arr[k]<=j&&ser[k]<ser[service]&&ser[k]>0)
					service=k;
			}
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(arr[i]<=j)
				{
					if(ser[i]<ser[service])
					{
						if(ser[i]>0)
						service=i;
					}
				}
			}
		}
	ser[service]=ser[service]-1;
	printf("In Service process at %d is:%d\n",j,service);
	for(i=0;i<n;i++)
	{
		if((arr[i]<=j||service==i)&&ser[i]!=0)
		tat[i]=tat[i]+1;
	}
}
for(i=0;i<n;i++)
{
	printf("Turn Around Time of %d is %d\n",i,tat[i]+1);
	sum1=sum1+tat[i]+1;
}
avg=sum1/n;
printf("Average Turn Around time=%f",avg);
}
void main(){
	int n,i;
	printf("Enter the no. of processes\n");
	scanf("%d",&n);
    printf("Enter the arrival time for processes\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("Enter the service time for processes\n");
	for(i=0;i<n;i++)
	scanf("%d",&ser[i]);
	srtn(n);
}

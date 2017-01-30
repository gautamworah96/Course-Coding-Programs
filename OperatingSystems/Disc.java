//ADITYA CHICHANI ROLL NO 9
package college;
import java.util.*;

public class Disk{
static int a[];
static int n,m,h;
public static void main(String args[])
{
Scanner sc=new Scanner(System.in);
System.out.println("Enter no of cylinders");
n=sc.nextInt();
System.out.println("Enter no of disk entries");
m=sc.nextInt();
a=new int[m+1];
System.out.println("Enter the entries");
for(int i=1;i<=m;i++)
 a[i]=sc.nextInt();
System.out.println("Enter header pointer");
a[0]=sc.nextInt();
System.out.println("FCFS "+ fcfs());
System.out.println("SSTF "+ sstf());
System.out.println("SCAN " + scan());
System.out.println("LOOK "+ look());
System.out.println("CSCAN " + cscan());
}
public static int fcfs(){
int b[]=new int[m+1];
for(int i=0;i<a.length;i++)
	b[i]=a[i];
int sum=0;
for(int i=1;i<=m;i++)
 sum+=Math.abs(b[i]-b[i-1]);
return sum;
}

public static int sstf(){
int b[][]=new int[a.length][a.length];
int c[]=new int[a.length];
c[0]=-1;
for(int i=0;i<a.length;i++)
{
	for(int j=(i+1);j<a.length;j++)
		b[j][i]=b[i][j]=Math.abs(a[i]-a[j]);
}
int min,index=0,count=1,i=0,sum=0;
while(count<a.length)
	{min=Integer.MAX_VALUE;
		for(int j=0;j<a.length;j++)
		{if(c[j]!=-1 && min>b[i][j])
				{min=b[i][j];
				 index=j;
				}
		}
		sum+=min;
		i=index;
		c[index]=-1;
		count++;
	}
return sum;
}

public static int scan(){
int b[]=new int[a.length];
for(int i=0;i<a.length;i++)
	b[i]=a[i];
int header=b[0];
int sum=0;
Arrays.sort(b);
for(int i=0;i<b.length;i++)
	if(b[i]==header)
		{header=i;
		break;
		}
for(int i=(a.length-1);i>0;i--)
	if(i!=(header+1))
	sum+=(b[i]-b[i-1]);
sum+=b[(header+1)]+b[0];
return sum;
}

public static int look(){
	int b[]=new int[a.length];
	for(int i=0;i<a.length;i++)
		b[i]=a[i];
	int header=b[0];
	int sum=0;
	Arrays.sort(b);
	for(int i=0;i<b.length;i++)
		if(b[i]==header)
			{header=i;
			break;
			}
	for(int i=(a.length-1);i>0;i--)
		if(i!=(header+1))
		sum+=(b[i]-b[i-1]);
	sum+=(b[(header+1)]-b[0]);
	return sum;
}

public static int cscan(){
	int b[]=new int[a.length];
	for(int i=0;i<a.length;i++)
		b[i]=a[i];
	int header=b[0];
	int sum=0;
	Arrays.sort(b);
	for(int i=0;i<b.length;i++)
		if(b[i]==header)
			{header=i;
			break;
			}
	for(int i=(a.length-1);i>0;i--)
		if(i!=(header+1))
		sum+=(b[i]-b[i-1]);
	sum+=b[0]+(n-1)+(n-1-b[a.length-1]);
	return sum;
}
}
/* OUTPUT:
Enter no of cylinders
200
Enter no of disk entries
5
Enter the entries
23 89 132 42 187
Enter header pointer
100
FCFS 421
SSTF 273
SCAN 287
LOOK 241
CSCAN 366
 */


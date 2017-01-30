#include <stdio.h>

int main()
{
    int r,p,total_r[100],i,j,allocated[10][100],max[10][100],count=0,completed[10]={0},available_r[100];

    printf("enter no of resources");
    scanf("%d",&r);

    printf("enter total instances of each resource");
    for (i=0;i<r;i++)
    {
        scanf("%d",total_r+i);
        available_r[i]=total_r[i];
    }

    printf("enter no of processes");
    scanf("%d",&p);

    printf("enter allocated matrix\n");
    for (i=0;i<p;i++)
    {
        for (j=0;j<r;j++)
        {
            scanf("%d",&allocated[i][j]);
            available_r[j]-=allocated[i][j];
        }
    }

    printf("enter the total need matrix\n");
    for (i=0;i<p;i++)
    {
        for (j=0;j<r;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    while (count!=p)
    {
        int safe=0;

        for (i=0;i<p;i++)
        {
            if (!completed[i])
            {
                for (j=0;j<r;j++)
                {
                    if (max[i][j]-allocated[i][j]>available_r[j])
                    {
                        break;
                    }
                }

                if (j==r)
                {
                    printf("P%d\t",i+1);
                    count++;

                    for (j=0;j<r;j++)
                    {
                        available_r[j]+=allocated[i][j];
                    }

                    completed[i]=1;
                    safe=1;
                    break;
                }
            }
        }

        if (!safe)
        {

            printf("its in unsafe state\n");
            break;
        }
    }

    return 0;
}



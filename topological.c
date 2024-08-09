#include<stdio.h>
#include<stdlib.h>
int indeg[10],a[10][10],flag[10],n;
void topology();
void main()
{
    int i,j;
    printf("enter vertices:\n");
    scanf("%d",&n);
    printf("\nenter adj matrix:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
    printf("topological viewing\n");
    topology();
}
void topology()
{
    int i,j, m=0,count=0;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    indeg[i]+=a[j][i];
    while(count<n)
    {
        m++;
        if(m==n)
        {
            printf("\ngraph is cyclic, not possible\n");
            exit(0);
            }
            for(i=1;i<=n;i++)
            {
                if(indeg[i]==0 && flag[i]==0)
                {
                    printf("\n %d",i);
                    count++;
                    flag[i]=1;
                    for(j=1;j<=n;j++)
                    if(a[i][j]==1)
                    indeg[j]--;
                }
            }
    }
}

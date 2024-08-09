#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[10][10];
int min(int a,int b)
{
    return a<b?a:b;
}
int floyd(int a[10][10],int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
}
void main()
{
    int i,j,n;
    clock_t start,end;
    int counter=0;
    printf("enter no of vertices:\n");
    scanf("%d",&n);
    printf("enter adj matrix:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
    start=clock();
    while(clock()-start<100)
    {
        counter++;
    floyd(a,n);
    }
    end=clock();
    printf("time taken is %f\n",(end-start)/18.26/counter);
    printf("resultant path matrix is:\n ");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
    printf("%d\t",a[i][j]);
    printf("\n");
        
    }

}

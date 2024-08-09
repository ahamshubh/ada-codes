#include<stdio.h>
#include<time.h>
int w[20],x[20],m,n;
int sumofsub(int s,int k,int r)
{
    int i;
    x[k]=1;
    if(s+w[k]==m)
    {
        printf("soln is\n");
        for(i=1;i<=n;i++)
        {
            printf("%d\t",x[i]);
        }
    }
    else
    {
    if(s+w[k]+w[k+1]<=m)
    sumofsub(s+w[k],k+1,r-w[k]);
    if(s+r-w[k]>=m && s+w[k+1]<=m)
    {
        x[k]=0;
        sumofsub(s,k+1,r-w[k]);
    }
    }
}
void main()
{
    int i,sum=0;
    clock_t start,end;
    printf("enter the nunber of elements:\n");
    scanf("%d",&n);
    printf("enter elements:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    sum+=w[i];
    x[i]=0;
    }
    printf("enter max element of subset:\n");
    scanf("%d",&m);
    printf("solution vector is\n");
    start=clock();
    sumofsub(0,1,sum);
    end=clock();
    printf("time taken is %f",(end-start)/(double)CLOCKS_PER_SEC);
}

#include<stdio.h>
#include<time.h>
int d[20],p[20],s[20],w[20][20],n,v;
int findmin()
{
    int i ,min;
    for(i=1;i<=n;i++)
    if(s[i]==0)
    {
        min=1;
        break;
    }
    for(i=1;i<=n;i++)
    {
        if(d[i]<d[min] && s[i]==0)
        min=i;
    }
    return min;
}
void dijk()
{
    int k,u,i,j,w1;
    for(i=1;i<=n;i++)
    {
        s[i]=0;
        d[i]=999;
        p[i]=0;
    }
    d[v]=0;
    for(k=1;k<=n;k++)
    {
        for(w1=1;w1<=n;w1++)
        {
            if(w[u][w1]!=999 && s[w1]==0)
            {
                if(d[w1]>d[u]+w[u][w1])
                {
                    d[w1]=d[u]+w[u][w1];
                    p[w1]=u;
                }
            }
        }
    }
    printf("shortest path costs\n");
    for(i=1;i<=n;i++)
    {
        if(d[i]==999)
        printf("\nno path from source %d to vertex %d\n",v,i);
        else
        printf("\npath cost from %d to %d is %d\n",v,i,d[i]);
    }
    printf("shortest group of paths are\n");
    for(i=1;i<=n;i++)
    {
        if(i!=v && d[i]!=999)
        {
            printf("%d",i);
            j=p[i];
            while(p[j]!=0)
            {
                printf("-->%d\n",j);
                j=p[j];
            }
            printf("-->%d\n",v);
        }
    }
}
void main()
{
    int i,j;
    clock_t st,end;
    printf("enter n of vertices:");
    scanf("%d",&n);
    printf("enter cost:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&w[i][j]);
    printf("enter source vertex:\n");
    scanf("%d",&v);
    st=clock();
    dijk();
    end=clock();
    printf("\ntime taken is %f",(end-st)/(double)CLOCKS_PER_SEC);
    
}

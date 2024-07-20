#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n,v,s[20],d[20],p[20],w[20][20],t[20][20];
int findmin()
    {
    int i,min;
    for(i=1;i<=n;i++)
    {
        if(s[i]==0)
        {
            min=1;
            break;
        }
    }
        for(i=1;i<=n;i++)
        {
            if(d[i]<d[min]&&s[i]==0)
            
                min=i;
            
        }
        return min;
    }
    
    void prims()
    {
        int k,u;
        for(int i=1;i<=n;i++)
        {
            s[i]=0;
            d[i]=999;
            p[i]=0;
        }
        s[v]=1;
        int x=0,sum=0;
        for(k=1;k<=n;k++)
        {
            u=findmin();
            t[x][0]=u;
            t[x][1]=p[u];
            x++;
            sum+=w[u][p[u]];
            s[u]=1;
            for(int w1=1;w1<=n;w1++)
            {
                if(w[u][w1]!=999&&s[w1]==0)
                {
                    if(d[w1]>w[u][w1])
                    {
                        d[w1]=w[u][w1];
                        p[w1]=u;
                    }
                }
            }
        }
        if(sum>999)
        {
            printf("min spanning tree doesnt exist");
        }
            else
        {
            printf("min cost spanning tree is:\n");
            for(int i=1;i<n;i++)
            {
                printf("\n%d->%d=%d\n",t[i][1],t[i][0],w[t[i][0]][t[i][1]]);
            }
            printf("\n min cost is %d",sum);
            
        }
        
    }
    void main()
    {
        int i,j,CLK_TCK;
        clock_t st,end;
        printf("\nenter number of nodes:");
        scanf("%d",&n);
        printf("\nenter cost adj matrix:\n");
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        scanf("%d",&w[i][j]);
        st=clock();
        prims();
        end=clock();
        printf("\ntime taken is:%f",(double)(end-st)/CLOCKS_PER_SEC);

//kruskal's algo
#include<stdio.h>
#include<time.h>
int a,b,u,v,i,j,k,n,ne=1;
int parent[9],min,mincost=0,cost[9][9];
int find(int);
int uni(int,int);
clock_t st,end;
int main()
    {
        printf("enter vertices:\n");
        scanf("%d",&n);
        printf("enter adj matrix:\n");
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=999;
        printf("min edge cost spanning tree is:\n");
        st=clock();
        while(ne<n)
        {
            for(i=1,min=999;i<=n;i++)
            for(j=1;j<=n;j++)
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                u=a=i;
                v=b=j;
            }
            u=find(u);
            v=find(v);
            if(uni(u,v))
            {
                printf("%d edge (%d,%d)=%d\n",ne++,a,b,min);
                mincost+=min;
            }
            cost[a][b]=cost[b][a]=999;
        }
        printf("min cost is:%d\n",mincost);
        end=clock();
        printf("time required is:%f",(double)(end-st)/CLOCKS_PER_SEC);
        return 0;
        }
int find(int i)
    {
        while(parent[i])
            i=parent[i];
            return i;
    }
int uni(int i,int j)
    {
        if(i!=j)
        {
            parent[j]=i;
            return 1;
        }
        return 0;
    }
        
        

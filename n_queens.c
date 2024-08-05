#include<stdio.h>
#include<time.h>
int i,j,k,count;
void ps(int n,int x[20])
{
    char c[10][10];
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    c[i][j]='x';
    for(i=1;i<=n;i++)
    c[i][x[i]]='q';
     for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
    printf("%c\t",c[i][j]);
    printf("\n");
}
}
int place(int x[20],int k)
{
    for(i=1;i<=k-1;i++)
    {
        if(x[i]-x[k]==i-k||x[i]==x[k]||i-x[i]==k-x[i]||i+x[i]==k+x[k])
        return 0;
    }
    return 1;
}
void nq(int n)
{
    int x[20];
    count=0;
    k=1;
    x[k]=0;
    while(k!=0)
    {
        x[k]+=1;
        while(x[k]<=n&&(!place(x,k)))
        {
            x[k]+=1;
        }
        if(x[k]<=n)
        {
        if(k==n)
        {
            count++;
            printf("solution is %d\n",count);
            ps(n,x);
        }
        else
        {
            k++;
            x[k]=0;
        }
    }
    else
    k--;
}
}
int main()
{
    int n;
    printf("no of queens:\n");
    scanf("%d",&n);
    nq(n);
    return (0);
}

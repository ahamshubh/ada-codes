#include<stdio.h>
#include<time.h>
int i,j,k,n,a[50][50],a[50][50],p[50][50];
void warshall(int n,int a[50][50], int p[50][50])
{
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    p[i][j]=a[i][j];
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(p[i][k]==1 && p[k][j]==1)
    p[i][j]=1;
}
void input(int n,int a[50][50])
{
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
}
void output(int n,int p[50][50])
{
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        printf("%d\t",p[i][j]);
        printf("\n");
        
    }
}
void main()
{
    int i,j;
    clock_t st,end;
    printf("enter number of nodes:\n");
    scanf("%d",&n);
    printf("enter adj matrix:\n");
    input(n,a);
    st=clock();
    warshall(n,a,p);
    end=clock();
    printf("tras matrix is:\n");
    output(n,p);
    printf("time taken is %f",(end-st)/(double)CLOCKS_PER_SEC);
}

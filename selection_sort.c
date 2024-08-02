#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selection(int a[],int n);
int n,i=0;
void main()
{
    clock_t start,end;
    printf("no of elements:\n");
    scanf("%d",&n);
    static int max=5000;
    int a[max];
    for(i=0;i<n;i++)
    a[i]=rand()%1000;
    printf("the elements are:\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    printf("\nelements after sorting:\n");
    start=clock();
    selection(a,n);
    end=clock();
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    printf("\ntime taken is %f sec",(end-start)/(double)CLOCKS_PER_SEC);
}
void selection(int a[],int n)
{
    for(i=0;i<n-1;i++)
    {
        int min=i,swap;
    for(int j=i+1;j<n;j++)
    {
        if(a[j]<a[min])
        {
            min=j;
        }
    }
        if(min!=i)
        {
            swap=a[i];
            a[i]=a[min];
            a[min]=swap;
        }
    }
}

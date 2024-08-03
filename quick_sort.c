#include<stdio.h>
#include<stdlib.h>
#include<time.h>
const int max=6000;
void qs(int a[],int low,int high);
int partition(int a[],int low,int high);
int i,n;
int partition(int a[],int low,int high)
{
    int temp,start,end,pivot;
    pivot=a[low];
    start=low;
    end=high;
    while(start<=end)
    {
        while(a[start]<=pivot)
        start++;
        while(a[end]>pivot)
        end--;
        if(start<end)
        {
            temp=a[start];
            a[start]=a[end];
            a[end]=temp;
        }
    }
       temp=a[low]; 
        a[low]=a[end];
        a[end]=temp;
        return end;
}
void qs(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
    mid=partition(a,low,high);
    qs(a,low,mid-1);
    qs(a,mid+1,high);
}
}
int main()
{
    clock_t start,end;
    int a[max];
    printf("no of elements:\n");
    scanf("%d",&n);
    printf("\ngenerating random integers\n");
    for(i=0;i<n;i++)
        a[i]=rand()%1000;
        printf("\nintegers are:\n");
        for(i=0;i<n;i++)
            printf("%d\t",a[i]);
    start=clock();
    qs(a,0,n-1);
    end=clock();
    printf("\nsorted elements are:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("time taken is: %f sec",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int,int,int);
void mergesort(int a[],int,int);
#define max 100
int i,j,k,n;
void main()
{
    clock_t start,end;
int a[max];
printf("enter the no of elements:\n");
scanf("%d",&n);
printf("\nrandom integers generated are:\n");
for(i=0;i<n;i++)
a[i]=rand()%1000;
for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\nsorted integers are:\n");
start=clock();
mergesort(a,0,n-1);
end=clock();
for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\ntime taken is %f sec",(double)(end-start)/CLOCKS_PER_SEC);
}
void mergesort(int a[],int low,int high)
{
    int mid;
       if(low<high)
       {
    mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
}
}
void merge(int a[],int low,int mid,int high)
{
    int i=low,k=low,j=mid+1,c[max];
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            c[k]=a[i];
            i+=1;
        }
        else
        {
            c[k]=a[j];
            j+=1;
        }
        k+=1;
    }
        if(k>mid)
            while(i<=mid)
            {
                c[k]=a[i];
                i+=1;
                k+=1;
            }
            while(j<=high)
            {
                c[k]=a[j];
                j+=1;
                k+=1;
            }
    for(i=low;i<=high;i++)
    a[i]=c[i];
}

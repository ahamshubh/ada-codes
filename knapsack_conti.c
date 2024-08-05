#include<stdio.h>
float knapsack(int n,float weight[],float profit[],float capacity);
int main()
{
    int n,items[10],i,j;
    float capacity,weight[10],profit[10],ratio[10],temp,result;
    printf("enter number of items:\n");
    scanf("%d",&n);
    printf("\nenter the items,weights,profits\n");
    for(i=0;i<n;i++)
    {
        printf("item %d:",i+1);
        scanf("%d\t%f\t%f",&items[i],&weight[i],&profit[i]);
    }
    printf("\nenter the capacity\n");
    scanf("%f",&capacity);
    for(i=0;i<n;i++)
    {
        ratio[i]=profit[i]/weight[i];
        }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
         if(ratio[i]<ratio[j])
         {
             temp=ratio[j];
             ratio[j]=ratio[i];
             ratio[i]=temp;
             temp=weight[j];
             weight[j]=weight[i];
             weight[i]=temp;
             temp=profit[j];
             profit[j]=profit[i];
             profit[i]=temp;
             int itemtemp=items[j];
             items[j]=items[i];
             items[i]=itemtemp;
         }
        }
    }
for(i=0;i<n;i++){
printf("%d\t%f\t%f\t%f\t\n",items[i],weight[i],profit[i],ratio[i]);
}
result=knapsack(n,weight,profit,capacity);
printf("max profit is:%f",result);
return 0;
}
float knapsack(int n,float weight[],float profit[],float capacity)
{
    int i;
    float u=capacity,finalprofit=0.0;
    for(int i=0;i<n;i++)
{
    if(weight[i]<=u)
    {
        u-=weight[i];
        finalprofit+=profit[i];
    }
    else
    {
        finalprofit+=profit[i]*(u/weight[i]);
        break;
    }
}
    return finalprofit;
}

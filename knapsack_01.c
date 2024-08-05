  #include<stdio.h>
  int weight[10],f[10][10],value[10],b[10],i,j;
  int max(int a, int b)
  {
      return (a>b)?a:b;
  }
  int knap(int i,int j)
  {
      if(i==0||j==0)
      f[i][j]=0;
      else if(j<weight[i])
      f[i][j]=knap(i-1,j);
      else
      f[i][j]=max(knap(i-1,j),value[i]+knap(i-1,j-weight[i]));
      return f[i][j];
  }
  void optimal(int i,int j)
  {
      if(i>=1||j>=1)
      if(f[i][j]!=f[i-1][j])
      {
          printf("item:%d\t",i);
          b[i]=1;
          j-=weight[i];
          optimal(i-1,j);
      }
      else
          optimal(i-1,j);
      
  }
  int main()
  {
      int profit,w1,n,i,j;
      printf("items?:\n");
      scanf("%d",&n);
      printf("capacity:\n");
      scanf("%d",&w1);
      printf("enter the weights:\n");
      for(i=1;i<=n;i++)
      scanf("%d",&weight[i]);
      printf("enter values:\n");
      for(i=1;i<=n;i++)
      scanf("%d",&value[i]);
      profit=knap(n,w1);
      printf("profit is:%d",profit);
      printf("\noptimal solution is:\n");
      optimal(n,w1);
      printf("\nsol vector is:\n");
      for(i=1;i<=n;i++)
      printf("%d",b[i]);
      return 0;
      
      
      
      
  }

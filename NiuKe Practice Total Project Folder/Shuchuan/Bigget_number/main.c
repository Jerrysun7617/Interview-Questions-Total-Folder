#include <stdio.h>
#include <stdlib.h>

int CompareInt(int a,int b)
{
     int a1=a,b1=b,la=10,lb=10;
     while(a/la)
     {
        la*=10;
     }
     while(b/lb)
     {
        lb*=10;
     }
     return (a*lb+b)-(b*la+a);
}
int main()
{
 int i,j,n;
 int data[100],temp;

 while(scanf("%d",&n))
 {
      if(n<=0||n>100) break;
      for(i=0;i<n;i++)
      {
            scanf("%d",&data[i]);
      }
      for(i=0;i<n-1;i++)
          for(j=i;j<n;j++)
          {
               if(CompareInt(data[i],data[j]) < 0)
               {
                    temp=data[i];
                    data[i]=data[j];
                    data[j]=temp;
               }
          }
      for(i=0;i<n;i++)
      {
        //longest =
        printf("%d",data[i]);
      }
        printf("\n");
 }
 return 0;
}

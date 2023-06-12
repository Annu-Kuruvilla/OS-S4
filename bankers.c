#include<stdio.h>
int main()
{
 int n, m, i, j, k;
n=5;
m=3;
 int alloc[5][3], max[5][3];
 int avail[3];
 printf("enter values of allocation matrix:\n");
 for(i=0;i<5;i++){
  for(j=0;j<3;j++){
    scanf("%d",&alloc[i][j]);
  }
 }
 printf("enter values of maximum matrix:\n");
 for(i=0;i<5;i++){
  for(j=0;j<3;j++){
    scanf("%d",&max[i][j]);
  }
 }
printf("enter values of available matrix:\n");
 for(i=0;i<3;i++){
    scanf("%d",&avail[i]);
  }
int f[n], ans[n], ind = 0;
for(k=0;k<n;k++)
 f[k]=0;
int need[n][m];
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
   need[i][j] = max[i][j] - alloc[i][j];
 }
int y=0;
 for(k=0;k<5;k++)
 {
  for(i=0;i<n;i++)
   {
    if(f[i]==0)
     {
      int flag=0;
      for(j=0;j<m;j++)
       {
        if(need[i][j]>avail[j])
        {
         flag=1;
         break;
        } 
       }
      if(flag==0)
     {
      ans[ind++] = i;
      for (y = 0; y < m; y++)
         avail[y] += alloc[i][y];
      f[i] = 1;
     }
    }
   }
 }
int flag =1;
for(int i=0;i<n;i++)
{
 if(f[i]==0)
{
 flag=0;
 printf("following system is not safe\n");
break;
}
}
if(flag==1)
{
 printf("following is a safe sequence\n");
 for(i = 0;i<n;i++)
 printf("P%d ->", ans[i]);
printf("P%d", ans[n-1]);
}
return (0);
}

#include<stdio.h>
int main()
{
 int n, bt[30], wt[30], tat[30],avwt=0, avtat=0, i, j;
 printf("Enter total number of processes:\n");
 scanf("%d",&n);
 printf("Enter process burst time\n");
 for(i=0;i<n;i++)
  {
   printf("P[%d]: ",i+1);
   scanf("%d",&bt[i]);
  }
 wt[0]=0;
 for(i=1;i<n;i++)
 {
  wt[i]=0;
   for(j=0;j<i;j++)
    wt[i]=wt[i]+bt[j];
 }
 printf("\nprocess\tbusrt time\twaiting time\tturn around time\n");
 for(i=0;i<n;i++)
 {
  tat[i]=bt[i]+wt[i];
  avwt+=wt[i];
  avtat+=tat[i];
  printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t\n",i+1,bt[i],wt[i],tat[i]);
 }
 avwt = avwt/n;
 avtat = avtat/n;
 printf("Average waiting time is %d\n",avwt);
 printf("Average turnaround time is %d\n", avtat);
 return 0;
}

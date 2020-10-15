#include<stdio.h>
#include<stdlib.h>
int main(){

	int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
	int n,sum=0,i;
	float totalTAT=0,totalWT=0;

	printf("Enter number of processes	");
	scanf("%d",&n);
	printf("Enter arrival time and burst time for each process\n\n");

	for( i=0;i<n;i++)
	{
		printf("Arrival time of process[%d]\t",i+1);
		scanf("%d",&at[i]);		
		printf("Burst time of process[%d]\t",i+1);
		scanf("%d",&bt[i]);		
		printf("\n");
	}
	
	for( i=0;i<n;i++)
	{
		sum=(at[i]>sum?at[i]:sum)+bt[i];
		ct[i]+=sum;
	}

	for( i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		totalTAT+=tat[i];
	}

	
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
		totalWT+=wt[i];
	}
	
	printf("Solution: \n\n");
	printf("P#\t AT\t BT\t CT\t TAT\t WT\t\n\n");
	
	for( i=0;i<n;i++)
	{
		printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
		
	printf("\n\nAverage Turnaround Time = %f\n",totalTAT/n);
	printf("Average WT = %f\n\n",totalWT/n);
	
	return 0;
}

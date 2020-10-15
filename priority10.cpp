#include<bits/stdc++.h> 
using namespace std; 
  
struct Process 
{ 
    int pid;  
    int bt;   
    int priority; 
}; 
  
bool comparison(Process a, Process b) 
{ 
    return (a.priority > b.priority); 
} 
  
void findWaitingTime(Process proc[], int n, int wt[]) 
{ 
    
    wt[0] = 0;    
    for (int  i = 1; i < n ; i++ ) 
        wt[i] =  proc[i-1].bt + wt[i-1] ; 
} 
  
void findTurnAroundTime( Process proc[], int n, int wt[], int tat[]) 
{ 
    for (int  i = 0; i < n ; i++) 
        tat[i] = proc[i].bt + wt[i]; 
} 
  
void findavgTime(Process proc[], int n) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
  
    findWaitingTime(proc, n, wt); 
    findTurnAroundTime(proc, n, wt, tat); 
  
    cout << "\nProcesses  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n"; 
  
    for (int  i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << "   " << proc[i].pid << "\t\t"
             << proc[i].bt << "\t    " << wt[i] 
             << "\t\t  " << tat[i] <<endl; 
    } 
  
    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n; 
} 
  
void priorityScheduling(Process proc[], int n) 
{ 
    sort(proc, proc + n, comparison); 
  
    cout<< "Order in which processes gets executed \n"; 
    for (int  i = 0 ; i <  n; i++) 
        cout << proc[i].pid <<" " ; 
  
    findavgTime(proc, n); 
} 
  
int main() 
{ 
    Process proc[10];
	int i,n;
	printf("Enter number of processes	");
	scanf("%d",&n);
	printf("Enter priority and burst time for each process\n\n");

	for( i=0;i<n;i++)
	{
		proc[i].pid=i+1;
		printf("Priority of process[%d]\t",i+1);
		scanf("%d",&proc[i].priority);		
		printf("Burst time of process[%d]\t",i+1);
		scanf("%d",&proc[i].bt);		
		printf("\n");
	}
    priorityScheduling(proc, n); 
    return 0; 
}

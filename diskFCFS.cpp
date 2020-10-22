#include <bits/stdc++.h> 
using namespace std; 

void FCFS(int arr[], int head,int size) 
{ 
    int seek_count = 0,i; 
    int distance, cur_track; 
    for (i = 0; i < size; i++) { 
        cur_track = arr[i]; 
        distance = abs(cur_track - head); 
        seek_count += distance; 
        head = cur_track; 
    } 
    cout << "Total number of seek operations = "<< seek_count << endl; 
    cout << "Seek Sequence is" << endl; 
    for (i = 0; i < size; i++)
	{ 
        cout << arr[i] << endl; 
    } 
} 
   
int main() 
{ 
    int n,i,head,m;
    cout<<"Enter the size of disk\n";
    cin>>m;
	cout<<"Enter no of requests : " ;
	cin>>n;
	cout<<"Enter initial head position : ";
	cin>>head;
	int arr[n];
	cout<<"Enter the requests in order\n";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]>m)
		{
		cout<<"Error, Unknown position\n";
		i--;}
	}
    FCFS(arr, head,n); 
    return 0; 
} 

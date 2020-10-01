#include <iostream> 
using namespace std; 

int main() 
{ 
	

	int n, m, i, j, k; 
	cout<<"Enter no of processes : ";
	cin>>n;
	cout<<"Enter no of resources : ";
	cin>>m;
	int alloc[n][m],max[n][m],need[n][m],avail[m];
	cout<<"Enter allocated resources: \n";
	for(i=0;i<n;i++)
	{
	    for(j=0;j<m;j++)
	    cin>>alloc[i][j];
	}
	cout<<"Enter max resources: \n";
	for(i=0;i<n;i++)
	{
	    for(j=0;j<m;j++)
	    cin>>max[i][j];
	}
	cout<<"Enter available resources: \n";
	for(i=0;i<m;i++)
	{
	    cin>>avail[i];
	}

	int f[n], ans[n], ind = 0; 
	for (k = 0; k < n; k++) { 
		f[k] = 0; 
	} 
	for (i = 0; i < n; i++) { 
		for (j = 0; j < m; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	int y = 0,flag; 
	for (k = 0; k < n; k++) 
	{ 
		for (i = 0; i < n; i++) 
		{ 
			if (f[i] == 0) 
			{ 

				flag = 0; 
				for (j = 0; j < m; j++) 
				{ 
					if (need[i][j] > avail[j])
					{ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) 
				{ 
					ans[ind++] = i; 
					for (y = 0; y < m; y++) 
						avail[y] += alloc[i][y]; 
					f[i] = 1; 
				} 
			}
			
		} 
		if(flag==1)
		{
		    cout<<"No safe sequence possible\n";
		    break;
		}
	} 
if(flag!=1){
	cout << "Following is the SAFE Sequence" << endl; 
	for (i = 0; i < n - 1; i++) 
		cout << " P" << ans[i] << " ->"; 
	cout << " P" << ans[n - 1] <<endl; 
}
	return (0); 
} 


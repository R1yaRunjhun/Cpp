#include<iostream> 
using namespace std; 
 
void findWaitingTime(int processes[], int n,int bt[], int wt[], int quantum) 
{ 
    
    int rem_bt[n]; 
    for (int i = 0 ; i < n ; i++) 
        rem_bt[i] =  bt[i]; 
  
    int t = 0; 
    while (1) 
    { 
        bool done = true; 
        for (int i = 0 ; i < n; i++) 
        { 
            if (rem_bt[i] > 0) 
            { 
                done = false; 
  
                if (rem_bt[i] > quantum) 
                { 
                    t += quantum; 
                    rem_bt[i] -= quantum;
					cout<<"P"<<i<<" " ;
                } 
                else
                { 
                    t = t + rem_bt[i]; 
                    wt[i] = t - bt[i];                    
                    rem_bt[i] = 0; 
                    cout<<"P"<<i<<" " ;
                } 
            } 
        } 
        if (done == true) 
          break; 
    } 
} 
void findResponseTime(int processes[],int n,int bt[],int res[],int quantum)
{
	res[0]=0;
	int r=0;
	for (int i = 1; i < n ; i++) 
	{
		if(bt[i]<quantum)
		{
		r+=bt[i];
		res[i]=r;
	    }
	    else
	    {
	    	r+=quantum;
			res[i]=r;
		}
	    
	}
}

void findTurnAroundTime(int processes[], int n,int bt[], int wt[], int tat[]) 
{ 
    
    for (int i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 

void findavgTime(int processes[], int n, int bt[],int quantum) 
{ 
    int wt[n], tat[n],res[n], total_wt = 0, total_tat = 0,total_res=0; 
    findWaitingTime(processes, n, bt, wt, quantum); 
    findTurnAroundTime(processes, n, bt, wt, tat); 
	findResponseTime(processes, n, bt,res, quantum);
    cout<<endl;
    cout << "Processes "<< " Burst time "<< " Waiting time " << " Turn around time"<<" Response Time\n"; 
    for (int i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i];  
        total_tat = total_tat + tat[i];
		total_res = total_res + res[i]; 
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "<< wt[i] <<"\t\t " << tat[i] <<"\t\t " <<res[i]<<endl; 
    } 
  
    cout << "Average waiting time = "<< (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n; 
    cout << "\nAverage response time = "<< (float)total_res/ (float)n;
} 
  
 
int main() 
{ 
	int n;
	cout<<"enter number of processes"<<endl;
	cin>>n;
    int processes[n];
    cout<<"enter the process id"<<endl;
    for(int i=0;i<n;i++)
    {
    	cin>>processes[i];
	}
    int burst_time[n]; 
    cout<<"enter the burst time of processes";
    for(int i=0;i<n;i++)
    {
    	cin>>burst_time[i];
	}
    int quantum ;
	cout<<"enter the value of quantum";
    cin>>quantum;
    findavgTime(processes, n, burst_time, quantum); 
    return 0; 
} 


#include<iostream> 
using namespace std; 
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
        cout << " " << bt[i] <<"\t "<< wt[i] <<"\t\t " << tat[i] <<"\t\t " <<res[i]<<endl; 
    } 
  
    cout << "Average waiting time = "<< (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n; 
    cout << "\nAverage response time = "<< (float)total_res/ (float)n;
} 
int main()
{
	int n;
	cout<<"Enter the number of process"<<endl;
	cin>>n;
	int Process_ID[n];
	int ArrivalTime[n];
	cout<<"Enter the Attribute of each process"<<endl;
    cout<<"(Process_ID,ArrivalTime)"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>Process_ID[i];
		cin>>ArrivalTime[i];
	}
	cout<<"Process ID"<<"      Arrival Time"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<Process_ID[i]<<"\t\t"<<ArrivalTime[i]<<endl;
	}
	findavgTime(, n, burst_time, quantum); 
    return 0; 
} 

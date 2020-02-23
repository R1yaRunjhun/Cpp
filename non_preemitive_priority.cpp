#include<iostream>
using namespace std;
int findResponseTime(int i,int at,int completeprocess,int rt)
{
	rt=completeprocess-at;
	return rt;
}
void findWatingTime(int processes[],int n,int tat[],int bt[],int wt[])
{
	for(int i =0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
	}
}
void findTurnAroundTime(int processes[],int n,int at[],int ct[],int tat[])
{
	for(int i =0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
	}
	
}


void findCompletionTime(int processes[], int n,int P[],int at[], int bt[],int rt[],int ct[])
{
	int order[n],temp[n],rembursttime[n];
	for(int i=0;i<n;i++)
	{
		order[i]=i;
		temp[i]=P[i];
		rembursttime[i]=bt[i];
	}
	
	int min=at[0];
	int k=0;
	for(int i=1;i<n;i++)
	{
	  if(min>at[i])
	  {
	  	  k=i;
	      min=at[i];	
	  }
    }
    int processshedule;
	processshedule = bt[k];
	ct[k] = bt[k];
	rembursttime[k] = 0;
	rt[k]=0;
	cout<<"P"<<processes[k]<<" ";
	
	int key,j;
	for(int i=1;i<n;i++)   //sorting start
	{
			key=temp[i];
			j=i-1;
			while(j>=0&& temp[j]>key)
			{
			 temp[j+1]=temp[j];
			 int z = order[j+1];
		 	 order[j+1]=order[j];
		 	 order[j]=z;
		  	 j=j-1;	
			}
		temp[j+1]=key;
		
	} //sorting end
	for(int i=0;i<n;i++)
	{
		if(rembursttime[order[i]]!=0 && at[order[i]]<processshedule)
		{	
			if(P[order[i]]==P[order[i]])
			{
				int quantum;
				cout<<"Enter the quantum"<<endl;
				cin>>quantum
				while (1) 
    			{ 
      				bool done = true; 
        	   		for (int i = 0 ; i < n; i++) 
       				{ 
            		if (rembursttime[i] > 0) 
            		{ 
                		done = false; 
 						if (rembursttime[order[i]] > quantum) 
               			{ 
                   		 t += quantum; 
                    	 rembursttime[i][i] -= quantum;
						 cout<<"P"<<i<<" " ;
                		} 
                		else
               			{ 
                   			t = t + rembursttime[order[i]]; 
                    		wt[order[i]] = t - bt[order[i]];                    
                    		rembursttime[order[i]]= 0; 
                    		cout<<"P"<<i<<" " ;
                		} 
            		} 
        		} 
        		if (done == true) 
         		break; 
    } 
				
			}
			else
			{
			int completeprocess= processshedule;
			processshedule+=bt[order[i]];
			ct[order[i]]=processshedule;
			rembursttime[order[i]] = 0;
			rt[order[i]]=findResponseTime(order[i],at[order[i]],completeprocess,rt[order[i]]);
			cout<<"P"<< processes[order[i]] <<" ";
			i=-1;
			}
		
		}
		
	
    }cout<<endl; 
}


void findaverageTimeNPPS(int Processes[], int n, int P[], int at[], int bt[])
{
	int ct[n],rt[n],tat[n],wt[n],total_rt=0,total_tat=0,total_wt=0;
	findCompletionTime(Processes,n,P,at,bt,rt,ct);
	findTurnAroundTime(Processes,n,at,ct,tat);
	findWatingTime(Processes, n,tat, bt, wt);

	
	cout << "Processes " <<"    Priority" << "  Arrival_Time"<<"   Burst_time " <<"   Completion_Time"<<"    Turn_around_time"<<"      Waiting_time " <<"    Response_Time""\n"; 
    for (int i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i];
		total_rt = total_rt + rt[i]; 
        cout<<" " << Processes[i]  <<"\t\t "<< P[i]<< "\t\t" << at[i] << "\t\t" <<bt[i]<<"\t\t" << ct[i] <<"\t\t " << tat[i] <<"\t\t " <<wt[i]<<"\t\t "<< rt[i]<<endl; 
    } 
  
    cout << "Average waiting time = "<< (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n; 
    cout << "\nAverage response time = " << (float)total_rt/ (float)n;
	
	
}
int main()
{
	int n;
	cout<<"Enter the number of process"<<endl;
	cin>>n;
	int Process_ID[n];
	int ArrivalTime[n];
	int BurstTime[n];
	int Priority[n];
	cout<<"Enter the Attribute of each process"<<endl;
    cout<<"(Process_ID,Priority,ArrivalTime,BurstTime )"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>Process_ID[i];
		cin>>Priority[i];
		cin>>ArrivalTime[i];
		cin>>BurstTime[i];
	}
	cout<<"Process ID"<<"     Priority"<<"    Arrival Time"<<"   BurstTime"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<Process_ID[i]<<"\t\t"<<Priority[i]<<"\t\t"<<ArrivalTime[i]<<"\t\t"<<BurstTime[i]<<endl;
	}
	
 
 findaverageTimeNPPS(Process_ID,n,Priority,ArrivalTime,BurstTime);
		
	
		
}

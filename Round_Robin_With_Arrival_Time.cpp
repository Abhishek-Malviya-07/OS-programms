#include<iostream>
using namespace std;
 
int main()
{
 
  int i,j,n,time,remain,flag=0,time_quantum;
  int wait_time=0,turnaround_time=0,process[10],at[10],bt[10],rt[10];
  cout<<"Enter Total Process:\t ";
  cin>>n;
  remain=n;
  

  for(i=0;i<n;i++)
  {
    
    cin>>process[i];
    
  }

  cout<<"Enter arrival time:";
  for(i=0;i<n;i++)
  {
    
    cin>>at[i];
    
  }

 cout<<"Enter burst time:";
  for(i=0;i<n;i++)
  {
    
    cin>>bt[i];
    rt[i]=bt[i];
    
  }
  
  cout<<"Enter Time Quantum:\t";
  cin>>time_quantum;
  cout<<"\n\nProcess\t|Turnaround Time|Waiting Time\n\n";
  for(time=0,i=0;remain!=0;)
  {
    if(rt[i]<=time_quantum && rt[i]>0)
    {
      time+=rt[i];
      rt[i]=0;
      flag=1;
    }
    else if(rt[i]>0)
    {
      rt[i]-=time_quantum;
      time+=time_quantum;
    }
    if(rt[i]==0 && flag==1)
    {
      remain--;
      cout<<process[i]<<"\t"<<time-at[i]<<"\t"<<time-at[i]-bt[i];
      wait_time+=time-at[i]-bt[i];
      turnaround_time+=time-at[i];
      flag=0;
    }
    if(i==n-1)
      i=0;
    else if(at[i+1]<=time)
      i++;
    else
      i=0;
  }
  cout<<"\nAverage Waiting Time= \n"<<wait_time*1.0/n;
  cout<<"\nAvg Turnaround Time =\n"<<turnaround_time*1.0/n;
  
  return 0;
}
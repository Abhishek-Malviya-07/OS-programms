#include<iostream>

using namespace std;

void sort(int process[],int n,int a[],int b[])
{
  int temp;
    for(int i=0;i<n;i++)
      {
         for(int j=i+1;j<n;j++)
          {
                if(b[i]>b[j])
                {
                      temp=a[i];
                      a[i]=a[j];
                      a[j]=temp;

                      temp=b[i];
                      b[i]=b[j];
                      b[j]=temp;
                }
          }
      }
}
int main()
{
      int n,temp,tt=0,min,d,i,j;
      float atat=0,awt=0,stat=0,swt=0;

      cout<<"enter no of process"<<endl;
      cin>>n;

      int process[n],a[n],b[n],e[n],tat[n],wt[n];
        for(i=0;i<n;i++)
      {
                  
            cin>>process[i];
      }
      
  
      cout<<"enter arival time ";
      for(i=0;i<n;i++)
      {
            
            cin>>a[i];
      }

       cout<<"enter brust time "; 
      for(i=0;i<n;i++)
      {
                
            cin>>b[i];
      }


    sort(process,n,a,b);

      min=a[0];
      for(i=0;i<n;i++)
      {
            if(min>a[i])
            {
                  min=a[i];
                  d=i;
            }
      }
      tt=min;
      e[d]=tt+b[d];
      tt=e[d];

      for(i=0;i<n;i++)
      {
            if(a[i]!=min)
            {
                  e[i]=b[i]+tt;
                  tt=e[i];
            }
      }
      for(i=0;i<n;i++)
      {

            tat[i]=e[i]-a[i];
            stat=stat+tat[i];
            wt[i]=tat[i]-b[i];
            swt=swt+wt[i];
      }
      atat=stat/n;
      awt=swt/n;
      cout<<"Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s)\n";

    for(i=0;i<n;i++)
    {
    cout<<process[i]<<"              "<<a[i]<<"                "<<b[i]<<"                  "<<wt[i]<<"               "<<tat[i]<<endl;
    }

    cout<<"Average Waiting Time:"<<awt<<endl;
    cout<<"Average TurnAround Time"<<atat;  
}
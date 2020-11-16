//Algoritma SJF
//Muhammad Abdul Ghani
//123180020

#include <iostream>

using namespace std;
 
int main(){
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    cout<<"Shortest Job First Scheduling With C++\n\n";
    cout<<"Masukkan Jumlah Proses : ";
    cin>>n;
 
    cout<<"\nMasukkan Burst Time:\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"] : ";
        cin>>bt[i];
        p[i]=i+1;           
    }
 
    //sorting burst time secara ascending dengan metode selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;            //waiting time pertama adalah 0
 
    //menghitung waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //AWT
    total=0;
 
    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //hitung turnaround time
        total+=tat[i];
        cout<<"\nP["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
    }
    
   	//Gant Chart
	cout<<"\n\n";
	cout<<"\t\t.:: Gant-Chart ::.\n";
	for(int i=0; i<n; i++){
	cout<<"P["<<p[i]<<"]|===";
	}
	cout<<"";
	cout<<"|\n";
	for(int j=0; j<n; j++){
			cout<<wt[j]<<"\t";
	}
	cout<<tat[j];
 
    avg_tat=(float)total/n;     //average turnaround time
    cout<<"\n\nAverage Waiting Time = "<<avg_wt;
    cout<<"\nAverage Turnaround Time = "<<avg_tat;
}

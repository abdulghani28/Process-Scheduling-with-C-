//Algoritma FIFO
//Muhammad Abdul Ghani
//123180020

#include <iostream>
 
using namespace std;
 
int main(){
    int n, bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    float avgwt, avgtat;
	
	cout<<"First In First Out Scheduling With C++\n\n";
    cout<<"Masukkan Jumlah Proses : ";
    cin>>n;
 
    cout<<"\nInput Burst Time\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"] : ";
        cin>>bt[i];
    }
 
    wt[0]=0;    //waiting time untuk proses pertama adalah 0
 
    //menghitung waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 
    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
 
    //menghitung turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }

	//Gant Chart
	cout<<"\n\n";
	cout<<"\t\t.:: Gant-Chart ::.\n";
	for(int j=0; j<n; j++){
	cout<<"P["<<j+1<<"]|===";
	}
	cout<<"";
	cout<<"|\n";
	for(int j=0; j<n; j++){
			cout<<wt[j]<<"\t";
	}
	cout<<tat[j];
	
    avgwt=(float)avwt/i;
    avgtat=(float)avtat/i;
    cout<<"\n\nAverage Waiting Time : "<<avgwt;
    cout<<"\nAverage Turnaround Time : "<<avgtat;
 
    return 0;
}



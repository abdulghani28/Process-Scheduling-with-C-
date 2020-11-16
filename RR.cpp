//Algoritma RR
//Muhammad Abdul Ghani
//123180020

#include <iostream>

using namespace std;

int main(){
	int st[10],bt[10],wt[10],tat[10],n,tq;
	int i,count=0,swt=0,stat=0,temp,sq=0;
	float awt=0.0,atat=0.0;
	
	cout<<"Round Robin Scheduling With C++\n\n";
	cout<<"Masukkan jumlah proses : ";
	cin>>n;

	cout<<"Masukkan Burst Time : \n";
	for(i=0;i<n;i++)
	{
		cout<<"P["<<i+1<<"] : ";cin>>bt[i];
		st[i]=bt[i];
	}
	
	cout<<"Masukkan Quantum : ";
	cin>>tq;
	
	while(1)
	{
		for(i=0,count=0;i<n;i++){
			temp=tq;
			if(st[i]==0){
				count++;
				continue;
			}
			if(st[i]>tq)	
				st[i]=st[i]-tq;
			else
			if(st[i]>=0){
				temp=st[i];
				st[i]=0;
			}
			sq=sq+temp;
			tat[i]=sq;
		}
		if(n==count)
		break;
	}
	
	for(i=0;i<n;i++){
		wt[i]=tat[i]-bt[i];
		swt=swt+wt[i];
		stat=stat+tat[i];
	}
	
	awt=(float)swt/n;
	atat=(float)stat/n;

	cout<<"\nAvg wait time is "<<awt;
	cout<<"\nAvg turn around time is "<<atat;
}

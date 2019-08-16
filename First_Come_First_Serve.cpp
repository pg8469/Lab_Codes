#include <bits/stdc++.h>
using namespace std;
bool comp(pair<float,pair<float,int> > a,pair<float,pair<float,int> > b){
	return a.first<b.first;
}
int main(){
	int n;
	cout<<"Enter number of processes"<<endl;
	cin>>n;
	pair<float,pair<float,int> > processes[n]; //Arrival time,Exec time,process id
	cout<<"Enter Arrival time and Exec time for each processe"<<endl;
	for(int i=0;i<n;i++){
		float at,et;
		cin>>at>>et;
		processes[i]=make_pair(at,make_pair(et,i));
	}
	sort(processes,processes+n,comp);
	float st[n],wt[n];
	st[0]=wt[0]=0;
	int i=0;
	printf("\n\n------------------------------------------------------------------------------------\n");
	cout<<"Process id\tArrival Time\tExec Time\tService time\tWaiting time"<<endl<<endl;
	printf("P%d\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n\n",processes[i].second.second,processes[i].first,processes[i].second.first,st[i],wt[i]);
	for(int i=1;i<n;i++){
		st[i]=st[i-1]+processes[i-1].second.first;
		wt[i]=st[i]-processes[i].first;
		printf("P%d\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n\n",processes[i].second.second,processes[i].first,processes[i].second.first,st[i],wt[i]);
	}
	float avgWt=0;
	for(int i=0;i<n;i++)
		avgWt+=wt[i];
	avgWt/=n;
	printf("Average Waiting time: %.2f\n",avgWt);
	printf("\n\n------------------------------------------------------------------------------------\n");
}
/* Arrival Time: Request time
	Service Time: Time at which process stared
	Waiting Time: When executed - when requested */
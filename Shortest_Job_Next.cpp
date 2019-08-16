#include <bits/stdc++.h>
using namespace std;
class Process{
public:
	float pid,at,et;
	float st,wt;
};

class myComparator 
{ 
public: 
    int operator() (const Process& p1, const Process& p2) 
    { 
        return p1.et > p2.et; 
    } 
}; 
int main(){
	int n;
	cout<<"Enter number of processes"<<endl;
	cin>>n;
	list<Process> Processes;
	cout<<"Enter Arrival time and Exec time for each processe"<<endl;

	for(int i=0;i<n;i++){
		float at,et;
		Process temp;
		cin>>temp.at>>temp.et;
		temp.pid=i;
		Processes.push_back(temp);
	}

	priority_queue<Process,vector<Process>, myComparator> toBeExecuted;
	toBeExecuted.push(Processes[0]);
	vector<Process> finished;
	int st=0;
	while(!toBeExecuted.empty()){
		Process execution=toBeExecuted.top();
		toBeExecuted.pop();
		execution.st=st;
		st+=execution.et;
		execution.wt=execution.st- execution.at;
		finished.emplaced_back(execution);

	}
}
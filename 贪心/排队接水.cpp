#include<bits/stdc++.h>
using namespace std;

// 排队人员类
class people{
public:
	int id;
	int time;
	people(int id = 0, int time = 0){
		this->id = id;
		this->time = time;
	}
	~people(){}
};

// 比较函数 - 升序排列
bool cmp(people a, people b){
	return a.time < b.time;
}

int main(){
	people list[1005];
	int n;
	cin>>n;
	for(int i = 1; i<=n; i++){
		int t = 0;
		cin>>t;
		people p(i, t);
		list[i] = p;
	}
	sort(list+1, list+n+1, cmp);
	for(int i = 1; i<=n; i++){
		cout<<list[i].id<<' ';
	}
	cout<<"\n";
	double totalWaitingTime = 0;
	for(int j = n-1; j>=1; j--){
		totalWaitingTime += list[n-j].time * j;
	}
	double averagetime = totalWaitingTime / n;
	printf("%.2lf", averagetime);
}
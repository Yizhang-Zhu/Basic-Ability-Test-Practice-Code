#include<bits/stdc++.h>
using namespace std;

// 写法一：pair
int n;
int a[1000005]; // start time 
int b[1000005]; // end time
pair<int, int> competition[1000005];

int main(){
	cin>>n;
	// 按结束时间早的排序
	for(int i = 1; i<=n; i++){
		cin>>a[i]>>b[i];
		// pair是字典序，所以把结束时间给first
		competition[i].first = b[i];
		competition[i].second = a[i];
	}
	sort(competition+1, competition+n+1);
	int cnt = 0;
	int t = 0;
	for(int i = 1; i<=n; i++){
		if(t <= competition[i].second){
			// t小于某比赛开始时间，则可参加
			cnt++;
			t = competition[i].first;
		}
	}
	cout<<cnt;
}

// 写法二：结构体
struct competition
{
	int a;
	int b;
}clist[1000005];

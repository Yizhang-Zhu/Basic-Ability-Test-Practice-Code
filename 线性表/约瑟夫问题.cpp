#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	int cnt = 1; // 报数器，从1开始报数
	queue<int> q;
	cin>>n>>m;
	for(int i = 1; i<=n; i++){
		q.push(i);
	}
	while(q.size() != 0){
		if(cnt == m){
			// 报到m，踢出，重新开始报数
			int n = q.front();
			cout<<n<<" ";
			q.pop();
			cnt = 1;
		}else{
			cnt++;
			// 队列头的数放回队尾
			int n = q.front();
			q.push(n);
			q.pop();
		}
	}
}
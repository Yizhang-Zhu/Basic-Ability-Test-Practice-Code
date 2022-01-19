#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt = 0; // 计数器
int x[5000005];

bool isPrime(int n){
	int t = sqrt(n) + 1;
	for(int i = 2; i<=t; i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

void dfs(int chosen, int sum, int index){
	// chosen:已经选了多少个
	// sum:当前的和
	// index:index保持增加，防止重复
	if(chosen == k){
		if(isPrime(sum) == true){
			cnt++;
		}
	}
	for(int i = index; i<=n; i++){
		dfs(chosen + 1, sum + x[i], i+1);
	}
	return;
}

int main(){
	cin>>n>>k;
	for(int i = 1; i<=n; i++){
		cin>>x[i];
	}
	dfs(0, 0, 1); // 下标从1开始
	cout<<cnt;

}
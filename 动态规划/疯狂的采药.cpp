#include<bits/stdc++.h>
using namespace std;

// 完全背包

int dp[10005][10005];
int t[10005];
int v[10005];
int n, c;

int main(){
	cin>>c>>n;
	for(int i = 1; i<=n; i++){
		cin>>t[i]>>v[i];
	}
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<=c; j++){
			for(int k = 0; k*t[i] <= j; k++){
				if(i == 0 || j == 0){
					dp[i][j] = 0;
				}else{
					dp[i][j] = max(dp[i][j], dp[i-1][j-k*t[i]]+k*v[i]); // 注意！！
				}
			}
		}
	}
	cout<<dp[n][c];
}
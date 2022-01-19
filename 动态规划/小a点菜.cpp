#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1005];
int dp[1005][1005]; // 前i种菜花j元钱 -- 方案数


int main(){
	cin>>n>>m;
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<=m; j++){
			if(j == a[i]){
				// 正好可以用掉，加一种方法
				dp[i][j] = dp[i-1][j] + 1;
			}else if(j < a[i]){
				// 这盘菜买不起
				dp[i][j] = dp[i-1][j];
			}else{
				// 这盘菜买得起:新总数 = 这盘菜买+不买
				dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i]];
			}
		}
	}
	cout<<dp[n][m];
}
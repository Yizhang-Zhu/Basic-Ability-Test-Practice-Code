#include<bits/stdc++.h>
using namespace std;

int n, c; // n件物品，背包容量c
int w[105];
int v[105];
int dp[105][105];
int maxvalue = 0;

int main(){
	cin>>n>>c;
	// 初始化
	for(int i = 1; i<=n; i++){
		cin>>w[i]>>v[i];
		dp[i][i] = 0;
	}
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<=c; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}else{
				if(j < w[i]){
					dp[i][j] = dp[i-1][j];
				}else{
					dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
					maxvalue = max(maxvalue, dp[i][j]);
				}
			}
		}
	}
	cout<<dp[n][c];
	// cout<<maxvalue;

}
#include<bits/stdc++.h>
using namespace std;

int w[1005];
int v[1005];
int dp[1005][1005];

int main(){
	int n, c;
	cin>>n>>c;
	for(int i = 1; i<=n; i++){
		cin>>w[i]>>v[i];
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
				}
			}
		}
	}
	cout<<dp[n][c];
}
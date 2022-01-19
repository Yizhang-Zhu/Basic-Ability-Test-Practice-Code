#include<bits/stdc++.h>
using namespace std;

int n;
int dp[5000][5000];

// 注意字符串下标从0开始

int main(){
	string a, b;
	cin>>a;
	cin>>b;
	int alen = a.size();
	int blen = b.size();
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i<alen; i++){
		for(int j = 0; j<blen; j++){
			if(a[i] == b[j]){
				dp[i+1][j+1] = dp[i][j] + 1;
			}else{
				dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
			}
		}
	}
	cout<<dp[alen][blen];
}
#include<bits/stdc++.h>
using namespace std;

int w[1005];
int v[1005];
int dp[1005][1005];
int path[1005][1005];
// vector<int> item;
int n, c;


int main(){
	cin>>n>>c;
	memset(path, 0, sizeof(path));
	for(int i = 1; i<=n; i++){
		cin>>w[i]>>v[i];
	}
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<=c; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}else{
				if(j < w[i]){ // 放不了
					dp[i][j] = dp[i-1][j];
				}else{
					dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
					if(dp[i][j] == dp[i-1][j-w[i]]+v[i]) path[i][j] = 1;
				}
			}
		}
	}
	// int index = n;
	// int contain = c;
	// while(contain>0){
	// 	if(path[index][contain] == 1){
	// 		item.push_back(v[index]);
	// 		contain -= w[index];
	// 	}
	// 	index--;
	// }
	cout<<"output:"<<endl;
	int i = n;
	int j = c;
	cout<<"chosen w and v:"<<endl;
	while(i>0 && j>0){
		if(path[i][j] == 1){
			cout<<w[i]<<" "<<v[i]<<" "<<endl;
			j -= w[i];
		}
		i--;
	}
	cout<<"max value:";
	cout<<dp[n][c];
}
#include <bits/stdc++.h>
using namespace std;

int n;
int s[12];
int b[12];
int minn = INT_MAX;

void dfs(int index, int chosen, int sour, int bitter){
	if(chosen >= 1){
		minn = min(minn, abs(sour-bitter));
	}
	for(int i = index; i<=n; i++){
		// 加入某个原料
		dfs(i+1, chosen+1, sour*s[i], bitter+b[i]);
		// 不加入
		dfs(i+1, chosen, sour, bitter);
	}
	return;

}


int main(){
	cin>>n;
	for(int i = 1; i<=n; i++){
		cin>>s[i]>>b[i];
	}
	dfs(1, 0, 1, 0);
	cout<<minn;
}
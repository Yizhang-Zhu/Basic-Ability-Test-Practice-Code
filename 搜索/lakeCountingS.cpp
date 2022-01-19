#include <bits/stdc++.h>
using namespace std;

int n,m;
int cnt = 0;
char graph[105][105];

void dfs(int x, int y){
	if(graph[x][y] == 'W'){
		// graph[x][y] = '.';
		for(int i = -1; i<=1; i++){
			for(int j = -1; j<=1; j++){
				dfs(x+i, y+j);
			}
		}
	}
	return;
}

int main(){
	cin>>n>>m;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cin>>graph[i][j];
		}
	}
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(graph[i][j] == 'W'){
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout<<cnt;
}

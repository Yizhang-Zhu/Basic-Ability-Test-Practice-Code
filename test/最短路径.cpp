#include<bits/stdc++.h>
using namespace std;

bool visited[10005] = {false};
int distence[10005];
int matrix[10005][10005];
int n, m, s;
const int inf = 0xfffffff;

// 本题是无向图，题设下标0开始


void dijkstra(int x){
	// 初始化
	for(int i = 0; i<n; i++){
		distence[i] = matrix[x][i];
	}
	// 更新distence
	for(int i = 0; i<n-1; i++){
		int temp_min = inf;
		int temp_index;
		// 找最小
		for(int j = 0; j<n; j++){
			if(visited[j] == false && temp_min > distence[j]){
				temp_min = distence[j];
				temp_index = j;
			}
		}
		visited[i] = true;
		// 更新
		for(int k = 0; k<n; k++){
			if(distence[k] > matrix[temp_index][k] + temp_min){
				distence[k] = matrix[temp_index][k] + temp_min;
			}
		}
	}
}


// 本题是有向图
int main(){
	cin>>n>>m;
	// matrix初始化
	for(int i = 0; i<n; i++){
		for(int j = 1; j<=n; j++){
			if(i == j){
				matrix[i][j] = 0;
			}else{
				matrix[i][j] = inf;
			}
		}
	}
	for(int i = 0; i<m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		matrix[u][v] = w;
		matrix[v][u] = w; // 如果是无向图就把这个加上
	}
	dijkstra(0);
	for(int i = 0; i<n; i++){
		if(distence[i] == inf){
			cout<<pow(2,31)-1<<" ";
		}else{
			cout<<distence[i]<<" ";
		}
	}
}
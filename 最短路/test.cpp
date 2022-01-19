#include<bits/stdc++.h>
using namespace std;

int matrix[10005][10005];
int distence[10005];
bool visited[10005] = {false};

int n, m, s;
const int inf = 0xfffffff;

void dijkstra(int x){
	// 初始化distence
	for(int i = 1; i<=n; i++){
		distence[i] = matrix[x][i];
	}
	// 更新distence数组
	for(int i = 1; i<=n-1; i++){
		int temp_min = inf;
		int temp_index;
		// 找距离顶点最小的且没被访问的
		for(int j = 1; j<=n; j++){
			if(distence[j] < temp_min && visited[j] == false){
				temp_min = distence[j];
				temp_index = j;
			}
		}
		// mark
		visited[i] = true;
		// 更新distence
		for(int k = 1; k<=n; k++){
			if(distence[k] > matrix[temp_index][k] + temp_min){
				distence[k] = matrix[temp_index][k] + temp_min;
			}
		}
	}
}

int main(){
	cin>>n>>m>>s;
	// 初始化matrix
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			if(i == j){
				matrix[i][j] = 0;
			}else{
				matrix[i][j] = inf;
			}
		}
	}
	// input
	for(int i = 1; i<=m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		matrix[u][v] = w;
	}
	dijkstra(s);
	for(int i = 1; i<=n; i++){
		cout<<distence[i]<<" ";
	}
}









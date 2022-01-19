#include <bits/stdc++.h>
using namespace std;

const int inf = 0xfffffff;

int n, m ,s; // 点数、有向边数、起始点
int matrix[10005][10005]; // 邻接矩阵
int distence[10005] = {inf}; // 各点与起点距离数组
bool visited[10005] = {false}; // true已访问，false未访问过

// 起始点为x，dijkstra算法
void dijkstra(int x){
	// 初始化distence
	for(int i = 1; i<=n; i++){
		distence[i] = matrix[x][i];
	}
	for(int i = 1; i<=n-1; i++){
		// 填写distence数组除了起点以外的空需要循环次数：n-1
		int temp_min = inf; // 这次选出的与起点距离最小的点 - 距离
		int temp_index; // 这次选出的与起点距离最小的点 - 标号
		// 从尚未访问的顶点中选择一个与起点距离最小的点
		for(int j = 1; j<=n; j++){
			if(visited[j] == false && distence[j] < temp_min){
				temp_min = distence[j];
				temp_index = j;
			}
		}
		// 上面选中的点标记已访问，继续判断distence表要不要更新
		visited[i] = true;
		for(int k = 1; k<=n; k++){
			if(matrix[temp_index][k] + distence[temp_index] < distence[k]){
				// 更短，则更新
				distence[k] = matrix[temp_index][k] + distence[temp_index];
			}
		}
	}
}

// 本题是有向图
int main(){
	cin>>n>>m>>s;
	// matrix初始化
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			if(i == j){
				matrix[i][j] = 0;
			}else{
				matrix[i][j] = inf;
			}
		}
	}
	for(int i = 1; i<=m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		matrix[u][v] = w;
		// matrix[v][u] = w; // 如果是无向图就把这个加上
	}
	dijkstra(s);
	for(int i = 1; i<=n; i++){
		if(distence[i] == inf){
			cout<<pow(2,31)-1<<" ";
		}else{
			cout<<distence[i]<<" ";
		}
	}
}
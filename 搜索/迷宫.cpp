#include<bits/stdc++.h>
using namespace std;

int n, m, t; // 行、列、障碍数
int sx, sy, fx,fy; // 起终点坐标
int graph[10][10]; // 1表示障碍，0表示可以通行
bool visited[10][10]; // true表示走过，false表示没走过
int cnt = 0; // counter

// x, y: 递归起点
void dfs(int x, int y){
	// 撞到边界
	if((x == 0 || x > m) || (y == 0 || y > m)){
		return;
	}
	// 撞到障碍
	if(graph[x][y] == 1){
		return;
	}
	// 吃回头草
	if(visited[x][y] == true){
		return;
	}
	// 到终点
	if(x == fx && y == fy){
		cnt++;
		return;
	}
	// 普通情况：上下左右，前进
	visited[x][y] = true;
	dfs(x+1, y);
	dfs(x-1, y);
	dfs(x, y+1);
	dfs(x, y-1);
	visited[x][y] = false; // 回溯！！别忘了！！
}

int main(){
	cin>>n>>m>>t;
	cin>>sx>>sy>>fx>>fy;
	for(int i = 1; i<=t; i++){
		int tx, ty; // 障碍坐标
		cin>>tx>>ty;
		graph[tx][ty] = 1;
	}
	dfs(sx, sy);
	cout<<cnt;
}
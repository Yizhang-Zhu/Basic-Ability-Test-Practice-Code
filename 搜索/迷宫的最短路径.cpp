// BFS
// 《挑战程序设计竞赛》 P34

#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000;

int n, m;
char maze[105][105]; // 迷宫
int d[105][105];
int sx, sy, gx, gy; // 起终点
int dx[4] = {1, 0, -1, 0}; // x方向数组
int dy[4] = {0, 1, 0, -1}; // y方向数组

typedef pair<int, int> P; // 坐标

// 求(sx, sy)到(gx, gy)的最短距离
int bfs(){
	queue<P> q;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			d[i][j] = INF; // init
		}
	}
	q.push(P(sx, sy));
	d[sx][sy] = 0;
	//bfs
	while(q.size() != 0){
		P p = q.front();
		q.pop();
		if(p.first == gx && p.second == gy){
			break; // 终点
		}
		// 上下左右四个方向走
		for(int i = 0; i<=4; i++){
			// 移动之后的新坐标
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			// 不超过边界，不碰到障碍，新坐标没被访问过
			if(nx>=1 && nx<=n && ny>=1 && ny<=m && maze[nx][ny] != '#' && d[nx][ny] == INF){
				q.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	return d[gx][gy];
}

int main(){
	cin>>n>>m;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cin>>maze[i][j];
			if(maze[i][j] == 'S'){
				sx = i;
				sy = j;
			}
			if(maze[i][j] == 'G'){
				gx = i;
				gy = j;
			}
		}
	}
	int minStepCnt = bfs();
	cout<<minStepCnt<<endl;
	// cout<<sx<<sy<<endl;
	// cout<<gx<<gy<<endl;
}
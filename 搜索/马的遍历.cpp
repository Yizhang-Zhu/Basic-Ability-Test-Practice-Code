#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n, m, x, y;
int minStepCnt[405][405];
int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={2,1,-1,-2,2,1,-1,-2};
bool visited[405][405];
queue<P> q;

void bfs(){
	q.push(P(x, y));
	visited[x][y] = true;
	while(q.size() != 0){
		P p = q.front();
		int kx = p.first;
		int ky = p.second;
		q.pop();
		for(int i = 0; i<8; i++){
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			// 不出边界，未被访问
			if(nx>=1 && nx<=n && ny>=1 && ny<=m && visited[nx][ny] == false){
				visited[nx][ny] = true;
				minStepCnt[nx][ny] = minStepCnt[kx][ky] + 1;
				q.push(P(nx, ny));
			}
		}
	}
}

int main(){
	cin>>n>>m>>x>>y;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			minStepCnt[i][j] = -1; // 初始化为不能到达
			visited[i][j] = false;
		}
	}
	minStepCnt[x][y] = 0;
	bfs();
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cout<<left<<setw(5)<<minStepCnt[i][j];
		}
		cout<<"\n";
	}

}
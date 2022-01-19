#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> P; // first记录终点，second记录起点(方便字典序)

// 邻接矩阵会爆，故采用邻接表
vector<P> edgePoint; // 存边的顶点
vector<int> edge[100005]; // 二维，存边的信息
bool Dvisited[100005] = {false};
bool Bvisited[100005] = {false};
int n, m;

// dfs, x表示所在点
void dfs(int x){
	Dvisited[x] = true;
	cout<<x<<" ";
	for(int i = 0; i<edge[x].size(); i++){
		int fpoint = edgePoint[edge[x][i]].first; // 终点
		if(Dvisited[fpoint] == false){
			dfs(fpoint);
		}
	}

}

// bfs
void bfs(int x){
	Bvisited[x] = true;
	queue<int> q;
	q.push(x);
	cout<<x<<" ";
	while(q.size() != 0){
		int point = q.front(); // 队首
		for(int i = 0; i<edge[point].size(); i++){
			int fpoint = edgePoint[edge[point][i]].first; // 终点
			if(Bvisited[fpoint] == false){
				q.push(fpoint);
				cout<<fpoint<<" ";
				Bvisited[fpoint] = true;
			}
		}
		q.pop();
	}
}

int main(){
	cin>>n>>m;
	for(int i = 0; i<m; i++){
		int s, f;
		cin>>s>>f;
		edgePoint.push_back(P(f, s));
	}
	sort(edgePoint.begin(), edgePoint.end());
	for(int i = 0; i<m; i++){
		edge[edgePoint[i].second].push_back(i);
	}
	dfs(1);
	cout<<"\n";
	bfs(1);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

// class edge{
// public:
// 	int from; // 起点
// 	int to; // 终点
// 	int weight; // 权重
// 	edge(int from = 0, int to = 0; int weight = 0){
// 		this->from = from;
// 		this->to = to;
// 		this->weight = weight;
// 	}
// 	~edge(){}
// };

struct edge{
	int from;
	int to;
	int weight;
}es[200005];

int parent[100005];
int n; // 顶点数
int m; // 边数
int titallength = 0; // 最小生成树路长
int cnt = 0;


// 并查集 找根结点
int find(int x){
	if(x == parent[x]){
		return x;
	}else{
		parent[x] = find(parent[x]);
		return parent[x];
	}
}

// 比较函数
bool cmp(edge e1, edge e2){
	return e1.weight < e2.weight;
}

// kruskal algo
void krukal(){
	// 边集排序 下标从1开始
	sort(es+1, es+1+m, cmp);
	for(int i = 1; i<=n; i++){
		int xr = find(es[i].from);
		int yr = find(es[i].to);
		// 如果不在一个集合就合并
		if(xr != yr){
			parent[yr] = xr;
			titallength += es[i].weight;
			cnt++;
			if(cnt == n-1) break;
		}
	}
}

int main(){
	cin>>n>>m;
	// 初始化
	for(int i = 1; i<=n; i++){
		parent[i] = i;
	}
	// input
	for(int i = 1; i<=m; i++){
		cin>>es[i].from>>es[i].to>>es[i].weight;
	}
	krukal();
	cout<<titallength;
}
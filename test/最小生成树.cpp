#include <bits/stdc++.h>
using namespace std;

class edge{
public:
	int from;
	int to;
	int weight;
};


int parent[100005];
edge es[100005];
int n, m; // 点数、边数
int len = 0;

// 找根
int find(int x){
	if(x == parent[x]){
		return x;
	}else{
		parent[x] = find(parent[x]);
		return parent[x];
	}
}

// cmp
bool cmp(edge e1, edge e2){
	return e1.weight < e2.weight;
}

// kruskal
void kruskal(){
	sort(es+1, es+1+m, cmp);
	for(int i = 0; i<m; i++){
		int xr = find(es[i].from);
		int yr = find(es[i].to);
		if(xr != yr){
			// 合并
			parent[xr] = yr;
			len += es[i].weight;
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i = 0; i<n; i++){
		parent[i] = i; // 初始的根节点是自己
	}
	for(int i = 0; i<m; i++){
		cin>>es[i].from>>es[i].to>>es[i].weight;
		// es[i].from--;
		// es[i].to--;
	}
	kruskal();
	cout<<len;
}
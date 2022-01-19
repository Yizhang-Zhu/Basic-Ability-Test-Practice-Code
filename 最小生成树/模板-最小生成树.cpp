// kruskal算法
#include<bits/stdc++.h>
using namespace std;

class edge{
public:
    int from; // 起点
    int to; // 终点
    int weight; // 权重
    edge(int from = 0, int to = 0, int weight = 0){
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
    ~edge(){}
};

edge es[2000005];
int parent[100005];
int n, m;
int len = 0;
// int cnt = 0;

// 比较函数
bool cmp(edge e1, edge e2){
    return e1.weight < e2.weight;
}

// 并查集找根
int find(int x){
    if(x == parent[x]){
        return x;
    }else{
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

// kruskal
void krukal(){
    // 边集排序
    sort(es+1, es+m+1, cmp);
    // 检验回路
    for(int i = 1; i<=m; i++){
        int xr = find(es[i].from); // 起点的根
        int yr = find(es[i].to); // 终点的根
        // 如果不在一个集合里（根不同）就合并集合
        if(xr != yr){
            parent[yr] = xr;
            len += es[i].weight;
            // cnt++;
            // if(cnt == n-1) break;
        }
    } 
}

int main(){
    cin>>n>>m;
    // 初始化
    for(int i = 1; i<=n; i++){
        parent[i] = i;
    }
    for(int i = 1; i<=m; i++){
        int x, y, z;
        cin>>x>>y>>z;
        es[i].from = x;
        es[i].to = y;
        es[i].weight = z;
    }
    krukal();
    cout<<len;
}
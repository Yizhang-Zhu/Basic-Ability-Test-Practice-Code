#include <bits/stdc++.h>
using namespace std;


// 一定要注意double！遇到double类型的数据先乘以1.0再说
class treasure{
public:
	int m;
	int v;
	double ppr; // Price–performance ratio
	treasure(int m = 0, int v = 0){
		this->m = m;
		this->v = v;
	}
	~treasure(){}
};

bool cmp(treasure a, treasure b){
	double appr = a.v*1.0 / a.m;
	double bppr = b.v*1.0 / b.m;
	return appr > bppr;
}

int main(){
	int n;
	int t; // 背包容量
	double max_value = 0; // 最大价值
	cin>>n>>t;
	treasure list[105];
	for(int i = 1; i<=n; i++){
		cin>>list[i].m>>list[i].v;
	}
	sort(list+1, list+n+1, cmp);
	for(int i = 1; i<=n; i++){
		if(t >= list[i].m){
			t -= list[i].m;
			max_value += list[i].v;
		}else{
			double ppr = list[i].v*1.0 / list[i].m;
			max_value += (ppr * t * 1.0);
			break;
		}
	}
	printf("%.2f", max_value);
}




// 结构体写法

// #include <bits/stdc++.h>
// using namespace std;

// struct treasure{
// 	int m;
// 	int v;
// 	double ppr;
// }tlist[105];

// bool cmp(treasure a, treasure b){
// 	return a.ppr > b.ppr;
// }

// int main(){
// 	int n;
// 	int t; // 背包容量
// 	double max_value = 0; // 最大价值
// 	cin>>n>>t;
// 	for(int i = 1; i<=n; i++){
// 		cin>>tlist[i].m>>tlist[i].v;
// 		tlist[i].ppr = tlist[i].v*1.0 / tlist[i].m;
// 	}
// 	sort(tlist+1, tlist+n+1, cmp);
// 	for(int i = 1; i<=n; i++){
// 		if(t >= tlist[i].m){
// 			t -= tlist[i].m;
// 			max_value += tlist[i].v;
// 		}else{
// 			max_value += (tlist[i].ppr * t * 1.0);
// 			break;
// 		}
// 	}
// 	printf("%.2lf", max_value);
// }
#include<bits/stdc++.h>
using namespace std;

int a[1000005] = {0};
int b[1000005];

bool cmp(int x, int y){
	return x < y;
}

int main(){
	int m, n;
	long long res = 0;
	cin>>m>>n;
	for(int i = 1; i<=m; i++){
		cin>>a[i];
	}
	sort(a+1, a+1+m, cmp);
	for(int i = 1; i<=n; i++){
		int b;
		cin>>b;
		int pos = 1;
		pos = lower_bound(a+1, a+m+1, b) - a;
		if(pos == m+1){
			res += (b - a[m]);
		}else{ 
			if(pos == 1){
				res += (a[1] - b);
			}else{
				res += min(abs(b - a[pos]), abs(b - a[pos-1]));
			}
		}
	}
	cout<<res;
	
}
#include<bits/stdc++.h>
using namespace std;

int num[2000002];

int main(){
	int n;
	int m;
	cin>>n>>m;
	for(int i = 0; i<m; i++){
		cin>>num[i];
	}
	sort(num, num+m);
	for(int i = 0; i<m; i++){
		cout<<num[i]<<' ';
	}
}
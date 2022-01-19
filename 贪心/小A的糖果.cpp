#include<bits/stdc++.h>
using namespace std;

int a[100002];

int main(){
	int n, x;
	cin>>n>>x;
	int res = 0;
	cin>>a[0];
	for(int i = 1; i<n; i++){
		cin>>a[i];
		if(a[i] + a[i-1] > x){
			res += (a[i] + a[i-1] - x);
			a[i] = a[i] - (a[i] + a[i-1] - x);
		}
	}
	cout<<res;
}
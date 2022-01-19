#include<bits/stdc++.h>
using namespace std;

int a[1000005];

// 在a数组二分查找x，下标从1开始
int bFind(int x, int len){
	int left = 1;
	int right = len;
	while(left < right){
		int mid = (left + right)/2;
		if(x <= a[mid]){
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	if(x == a[left]){
		return left; // 此时left就是x的下标
	}else{
		return -1; // not found
	}
}

// // 手写二分
// int main(){
// 	int n, m;
// 	cin>>n>>m;
// 	// input a 
// 	for(int i = 1; i<=n; i++){
// 		cin>>a[i];
// 	}
// 	// input and find
// 	for(int i = 1; i<=m; i++){
// 		int x;
// 		cin>>x;
// 		int pos = bFind(x, n);
// 		cout<<pos<<" ";
// 	}
// }


// STL
int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	for(int i = 1; i<=m; i++){
		int x;
		cin>>x;
		int pos = lower_bound(a+1, a+n+1, x) - a; // 注意减去a
		if(x == a[pos]){
			cout<<pos<<" ";
		}else{
			cout<<-1<<" ";
		}
	}
}
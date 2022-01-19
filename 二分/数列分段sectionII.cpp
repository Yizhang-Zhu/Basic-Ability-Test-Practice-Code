#include<bits/stdc++.h>
using namespace std;

int a[100005];

// 判断答案为x时分割是否可行
bool judge(int x, int n, int m){
	int cnt = 1; // 划分数目从1开始！
	int tempSum = 0;
	for(int i = 1; i<=n; i++){
		if(a[i] > x){
			return false; // 数组中某元素比测试数还大，直接不行
		}else{
			if(tempSum + a[i] <= x){
				tempSum += a[i]; // 当前元素可以放入此次划分
			}else{
				tempSum = a[i]; // 当前元素不能放入此次划分，开启新的一个划分
				cnt++;
			}
		}
	}
	return (cnt <= m);
}


int main(){
	int n, m;
	int sum = 0;
	int maxn = 0;
	cin>>n>>m;
	for(int i = 1; i<=n; i++){
		cin>>a[i];
		sum += a[i];
		maxn = max(maxn, a[i]);
	}
	int left = maxn; // 理论答案的最小值
	int right = sum; // 理论答案的最大值
	int mid;
	while(left < right){
		mid = (left + right) / 2;
		if(judge(mid, n, m) == true){
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	cout<<left;
}
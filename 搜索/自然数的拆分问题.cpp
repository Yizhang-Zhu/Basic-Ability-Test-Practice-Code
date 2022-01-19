#include<bits/stdc++.h>
using namespace std;

int n;
int ans[10] = {1};



// 格式化输出
void output(int x){
	cout<<ans[1];
	for(int i = 2; i<=x; i++){
		cout<<"+"<<ans[i];
	}
	cout<<"\n";
}

//dfs
void dfs(int leftSum, int index){
	for(int i = ans[index-1]; i<=leftSum; i++){ // 当前的数要大于前一个数：ans[index-1]
		if(i < n){ // 不能比n大
			ans[index] = i;
			leftSum -= i;
			if(leftSum == 0){
				output(index);
			}else{
				dfs(leftSum, index+1); // 继续递归
			}
			leftSum += i; //回溯：加回拆分出的数，以拆分出所有可能
		}
	}
}

int main(){
	cin>>n;
	dfs(n, 1);
}
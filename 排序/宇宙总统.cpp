#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string max_num = "";
	string num = "";
	int id;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		cin>>num;
		int num_len = num.length();
		int max_len = max_num.length();
		if (num_len > max_len || (num > max_num && num_len >= max_len) )
		{
			id = i;
			max_num = num;
		}
	}
	cout<<id<<'\n'<<max_num<<'\n';

}
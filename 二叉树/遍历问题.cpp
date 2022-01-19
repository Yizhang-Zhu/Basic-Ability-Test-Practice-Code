#include<bits/stdc++.h>
using namespace std;

char s1[1000];
char s2[1000];
int cnt = 0;

// 转化为寻找单链数目 即前序是XY，后序为YX就满足
int main(){
	cin>>s1>>s2;
	for(int i = 0; i<strlen(s1); i++){
		for(int j = 1; j<strlen(s2); j++){
			if(s1[i] == s2[j] && s1[i+1] == s2[j-1]){
				cnt++;
			}
		}
	}
	long long res = pow(2, cnt);
	cout<<res;
}

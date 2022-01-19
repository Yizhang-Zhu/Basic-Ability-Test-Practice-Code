#include<bits/stdc++.h>
using namespace std;

char c;
stack<int> s;

int main(){
	while(cin>>c){
		if(c == '@'){ break; }
		if(c >= '0' && c <= '9'){
			int num = c - '0';
			// 可能不是个位数
			while(cin>>c && c >= '0' && c <= '9'){
				num = num * 10 + (c - '0');
			}
			s.push(num);
		}
		if(c == '+'){
			int x = s.top();
			s.pop();
			int y = s.top();
			s.pop();
			s.push(y+x);
		}
		if(c == '-'){
			int x = s.top();
			s.pop();
			int y = s.top();
			s.pop();
			s.push(y-x);
		}
		if(c == '*'){
			int x = s.top();
			s.pop();
			int y = s.top();
			s.pop();
			s.push(y*x);
		}
		if(c == '/'){
			int x = s.top();
			s.pop();
			int y = s.top();
			s.pop();
			s.push(y/x);
		}
	}
	int res = s.top();
	cout<<res;
}
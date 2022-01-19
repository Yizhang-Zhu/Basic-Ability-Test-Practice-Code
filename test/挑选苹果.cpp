#include<bits/stdc++.h>
using namespace std;

struct{
	int busket;
	string id;
	int w;
	int d;
}appleList[1000005];

int main(){
	int n;
	vector<int> blist; // 篮筐号列表
	vector<int> res;
	cin>>n;
	for(int i = 1; i<=n; i++){
		cin>>appleList[i].busket>>appleList[i].id>>appleList[i].w>>appleList[i].d;
		blist.push_back(appleList[i].busket);
	}
	for(int i = 1; i<=blist.size(); i++){			
		int maxw = 0;
		int maxi = 0;
		for(int j = 1; j<=n; j++){
			if(appleList[j].busket == i && appleList[j].w > maxw){
				maxw = appleList[j].w;
				maxi = j;
			}
		}
		res.push_back(maxi);
	}
	for(int i = 0; i<res.size(); i++){
		int index = res[i];
		if(appleList[index].busket != 0)
			cout<<appleList[index].busket<<' '<<appleList[index].id<<' '<<appleList[index].w<<' '<<appleList[i].d<<'\n';
	}
}
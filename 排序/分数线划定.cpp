#include<bits/stdc++.h>
using namespace std;

class candidate{
public:
	int id;
	int score;
	// construction
	candidate(int id = 0, int score = 0){
		this->id = id;
		this->score = score;
	}
	// destrucion
	~candidate(){}
};

// compare
bool compare(candidate x, candidate y){
	if(x.score != y.score){
		return x.score > y.score;
	}else{
		return x.id < y.id;
	}
}

int main()
{
	int n, m;
	cin>>n>>m;
	int id;
	int score;
	candidate clist[5005];
	for (int i = 0; i < n; ++i)
	{
		cin>>id>>score;
		candidate c(id, score);
		clist[i] = c;
	}
	sort(clist, clist+n, compare);
	int interview_num = floor(double(m*1.50));
	int score_line = clist[interview_num-1].score;
	int cnt = 0;
	for(int i = 0; i<n; i++){
		if(clist[i].score >= score_line){
			cnt++;
		}else{
			break;
		}
	}
	cout<<score_line<<" "<<cnt<<'\n';
	for(int i = 0; i<cnt; i++){
		cout<<clist[i].id<<" "<<clist[i].score<<"\n";
	}
	return 0;
}
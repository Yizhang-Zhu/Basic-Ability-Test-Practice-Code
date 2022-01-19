#include<bits/stdc++.h>
using namespace std;

// 学生类
class student{
public:
	int id; // 学号
	int yw; // 语文
	int sx; // 数学
	int yy; // 英语
	int sum; // 总分
	// construction 
	student(int id = 0, int yw = 0, int sx = 0, int yy = 0, int sum = 0){
		this->id = id;
		this->yw = yw;
		this->sx = sx;
		this->yy = yy;
		this->sum = this->yw + this->sx + this->yy;
	}
	// destruction
	~student(){}
};

// 比较函数
bool compare(student x, student y){
	if(x.sum != y.sum){
		return x.sum > y.sum;
	}else{
		// 比较语文成绩
		if(x.yw != y.yw){
			return x.yw > y.yw;
		}else{
			//比较id
			return x.id < y.id;
		}
	}

}

int main(){
	int n;
	cin>>n;
	student slist[305]; // student list
	int id; // 学号
	int yw; // 语文
	int sx; // 数学
	int yy; // 英语
	int sum; // 总分
	for(int i = 0; i<n; i++){
		cin>>yw>>sx>>yy;
		id = i+1;
		// sum = yw+sx+yy;
		student s(id, yw, sx, yy, sum);
		slist[i] = s;
	}
	sort(slist, slist+n, compare);
	for(int i = 0; i<5; i++){
		cout<<slist[i].id<<" "<<slist[i].sum<<"\n";
	}
}
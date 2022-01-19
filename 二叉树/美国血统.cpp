#include <bits/stdc++.h>
using namespace std;

string inTree, preTree;

// inLeft、inRight: 中序遍历范围
// preLeft、preRight: 前序遍历范围
void findPostorder(int inLeft, int inRight, int preLeft, int preRight){
	if(inLeft > inRight || preLeft > preRight){
		return; // 到头了
	}
	for(int i = inLeft; i<=inRight; i++){
		// 在中序的string里找前序遍历string的第一个字符，即为根节点
		if(inTree[i] == preTree[preLeft]){
			// 左子树
			findPostorder(inLeft, i-1, preLeft+1, preLeft+(i-inLeft));
			// 右子树
			findPostorder(i+1, inRight, preLeft+(i-inLeft)+1, preRight);
			// 后序遍历，后输根节点
			cout<<inTree[i];
		}
	}
}

int main(){
	cin>>inTree>>preTree;
	// 注意下标，字符串下标0开始
	findPostorder(0, inTree.length()-1, 0, inTree.length()-1);
}
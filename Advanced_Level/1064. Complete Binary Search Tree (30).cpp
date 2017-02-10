#include<iostream>
#include<algorithm>//使用sort函数
#include<vector>
using namespace std;

vector<int> T;//存储层序结果的数组
vector<int> inorder;//存储中序序列的数组
int N;

void Build(int root, int &pos);//dfs构建完全二叉树

/*
题意：
给出一个序列，构建出它的完全二叉搜索树， 然后输出层序。
思路：
BST问题。
二叉搜索树的性质，其中序是有序的。
完全二叉树的性质，根结点编号i，则左孩子2i， 右孩子2i+1.
而且完全二叉树是可以用数组来存储的，正好就是层序序列。

知道上面的性质，想必我们就有思路了。
不就是根据中序利用完全二叉树性质建树吗。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	cin >> N;
	T.resize(N + 1);
	inorder.resize(N);

	for (int i = 0; i < N; i++)
		cin >> inorder[i];
	sort(inorder.begin(), inorder.end());//升序序列
	int pos = 0;//建树的起始位置
	Build(1, pos);//dfs建树

	for (int i = 1; i <= N; i++)//输出
	{
		if (i == 1)
			cout << T[i];
		else
			cout << ' ' << T[i];
	}
	cout << endl;

	return 0;
}

void Build(int root, int &pos)//dfs构建完全二叉树，pos要用引用
{
	if (root > N)//递归结束条件
		return;

	int left = root << 1;//左孩子编号
	int right = left + 1;
	Build(left, pos);//先递归左子树
	T[root] = inorder[pos++];//得到父结点值，pos自增
	Build(right, pos);

	return;
}

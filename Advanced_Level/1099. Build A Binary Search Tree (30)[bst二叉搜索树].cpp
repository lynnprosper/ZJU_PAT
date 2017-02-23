#include<iostream>
#include<vector>
#include<algorithm>//使用sort函数
#include<queue>
using namespace std;

struct Node
{
	int val;//该结点的值
	int left, right;//分别为左右结点的编号
};
int N, index = 0;//分别为结点数，中序遍历时的索引
vector<Node> T;//数组表示二叉树
vector<int> inor;//存储中序遍历的序列

void levelTraversal(int root);//层序遍历输出
void Inorder(int root);//中序遍历给结点赋值

/*
题意：
给出二叉搜索树的结构及结点的值，求出层序序列。
思路：
首先我们要知道BST的中序是升序序列，这样的话，我们就知道了
BST的中序序列。
所以有多种方法。可以构建树，然后再中序遍历同时回填元素值。
也可以不用，因为已经知道了结构，可以用数组模拟二叉树的形式中序遍历，再回填值。
最后用队列层序输出。
这里用第二个简便些。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	cin >> N;
	T.resize(N);//数组表示二叉树
	inor.resize(N);//存储中序遍历的序列

	for (int i = 0; i < N; i++)//读入数据
		cin >> T[i].left >> T[i].right;
	for (int i = 0; i < N; i++)
		cin >> inor[i];

	sort(inor.begin(), inor.end());//升序
	Inorder(0);//中序遍历给结点赋值
	levelTraversal(0);//层序遍历输出

	return 0;
}

void Inorder(int root)//递归中序遍历给结点赋值
{
	if (root == -1)//递归结束条件
		return;

	Inorder(T[root].left);//遍历左结点
	T[root].val = inor[index++];//赋值
	Inorder(T[root].right);//遍历右结点
	
	return;
}

void levelTraversal(int root)//层序遍历输出
{
	queue<int> Q;
	Q.push(root);
	cout << T[root].val;

	while (!Q.empty())
	{
		int id = Q.front();
		Q.pop();
		
		if (T[id].left != -1)
		{
			Q.push(T[id].left);
			cout << ' ' << T[T[id].left].val;
		}
		if (T[id].right != -1)
		{
			Q.push(T[id].right);
			cout << ' ' << T[T[id].right].val;
		}
	}

	cout << endl;
	return;
}

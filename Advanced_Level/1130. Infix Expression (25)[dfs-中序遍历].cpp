#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
	string data;
	int left, right;
};
vector<Node> T;
int Root;//存储根节点编号

void dfs(int root);//递归输出表达式

/*
题意：给出一颗二叉树，输出其中缀表达式。
思路：
题意不难。中序遍历就行了，不过难点在于括号的输出。
递归的时候，加个判断条件。
只要当前遍历的不是根结点且左右不全空，就输出括号。
已AC。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int N;
	cin >> N;
	T.resize(N + 1);
	vector<int> id(N + 1, 0);

	for (int i = 1; i <= N; i++)//读入数据
	{
		cin >> T[i].data >> T[i].left >> T[i].right;
		if (T[i].left != -1)
			id[T[i].left] = 1;
		if (T[i].right != -1)
			id[T[i].right] = 1;
	}
	
	for (int i = 1; i <= N; i++)//找出根结点编号
	{
		if (id[i] == 0)
		{
			Root = i;
			break;
		}
	}
	dfs(Root);

	return 0;
}

void dfs(int root)
{
	if (root == -1)
		return;
	bool hasPth = false;//判断是否输出括号
	if (root != Root && (T[root].left != -1 || T[root].right != -1))
		hasPth = true;
	if (hasPth)
		cout << '(';

	dfs(T[root].left);
	cout << T[root].data;
	dfs(T[root].right);

	if (hasPth)
		cout << ')';

	return;
}

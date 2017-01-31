#include<iostream>
#include<vector>
using namespace std;

vector<int> seq, pos, posm;//分别表示已知序列， 后序和镜像后的后序序列
vector<int> pre, prem;//分别表示先序和镜像后的先序序列
struct Node//二叉树结点
{
	Node() : left(NULL), right(NULL) {}
	int data;
	Node *left, *right;
};
Node *T = NULL;//树的根
int N;

void Insert(Node *&T, int d);//一个元素插入树中
void Preord(Node *T);//先序遍历
void Premord(Node *T);//镜像后的先序遍历
void Postord(Node *T);//后序遍历
void Postmord(Node *T);//镜像后的后序遍历
void Print(vector<int> &v);//输出

/*
题意：
判断给出的序列是否二叉搜索树的先序或者镜像后的先序，是的话，输出后序。
思路：
因为给出的不一定是BST，所以我们先假设是，按照BST的特性依次插入建树。
然后再先序遍历该树，和给出的序列相同，则是。最后后序遍历，输出即可。
不难，但是有点麻烦。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)//读入数据
	{
		int tem;
		cin >> tem;
		seq.push_back(tem);
		Insert(T, tem);
	}

	Preord(T);
	Premord(T);
	if (pre == seq)//判断是先序还是镜像的先序
	{
		Postord(T);
		Print(pos);
	}
	else if (prem == seq)//镜像的先序输出镜像的后序
	{
		Postmord(T);
		Print(posm);
	}
	else
		cout << "NO" << endl;

	return 0;
}

void Insert(Node *&T, int d)//一个元素插入树中，注意要用指针的指针
{
	if (T == NULL)
	{
		T = new Node;
		T->data = d;
		return;
	}
	else if (d < T->data)
		Insert(T->left, d);
	else
		Insert(T->right, d);
	
	return;
}

void Preord(Node *T)//先序dfs遍历
{
	if (T == NULL)
		return;

	pre.push_back(T->data);
	Preord(T->left);
	Preord(T->right);
}

void Premord(Node *T)//镜像后的先序遍历,即根右左
{
	if (T == NULL)
		return;

	prem.push_back(T->data);
	Premord(T->right);
	Premord(T->left);
}

void Postord(Node *T)//后序遍历
{
	if (T == NULL)
		return;
	Postord(T->left);
	Postord(T->right);
	pos.push_back(T->data);
}

void Postmord(Node *T)//镜像后的后序遍历，即右左根
{
	if (T == NULL)
		return;
	Postmord(T->right);
	Postmord(T->left);
	posm.push_back(T->data);
}

void Print(vector<int> &v)//输出
{
	cout << "YES\n";
	for (unsigned i = 0; i < v.size(); i++)
	{
		if (i == 0)
			cout << v[i];
		else
			cout << ' ' << v[i];
	}
	cout << endl;
}

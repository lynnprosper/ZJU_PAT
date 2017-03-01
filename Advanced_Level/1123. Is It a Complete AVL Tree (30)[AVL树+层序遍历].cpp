#include<iostream>
#include<algorithm>//使用max函数
#include<queue>
using namespace std;

struct Node
{
	Node() : left(NULL), right(NULL) {}//指针初始为空
	int data;
	Node *left, *right;
};
Node *T = NULL;//树的根结点
int N;//总结点数

int getH(Node *T);//取得树深度
Node *sinL(Node *T);//左单旋
Node *sinR(Node *T);//右单旋
Node *douLR(Node *T);//左右双旋
Node *douRL(Node *T);//右左双旋
Node *Insert(Node *T, int d);//插入构建AVL树
void levelOrder();//层序遍历

/*
题意：
构建AVL, 层序输出，再判断该树是否完全二叉树。
思路：
题意不难，只是有些麻烦。
根据AVL特点，先建树，构建的时候进行平衡处理。之后用队列输出层序。
层序过程中，如果没有遍历完结点，出现了空结点，那么不是完全二叉树。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int d;
		cin >> d;
		T = Insert(T, d);
	}
	levelOrder();

	return 0;
}

int getH(Node *T)//取得树深度
{
	if (T == NULL)
		return 0;
	else
		return(max(getH(T->left), getH(T->right)) + 1);//递归
}

Node *sinL(Node *T)//左单旋
{
	Node *A = T->right;
	T->right = A->left;
	A->left = T;
	return A;//新的根结点
}
Node *sinR(Node *T)//右单旋
{
	Node *A = T->left;
	T->left = A->right;
	A->right = T;
	return A;
}

Node *douLR(Node *T)//左右双旋
{
	T->left = sinL(T->left);//先左旋
	T = sinR(T);//再右旋
	return T;
}

Node *douRL(Node *T)//右左双旋
{
	T->right = sinR(T->right);
	T = sinL(T);
	return T;
}

Node *Insert(Node *T, int d)//递归插入构建AVL树
{
	if (T == NULL)//递归结束条件
	{
		T = new Node;
		T->data = d;
	}
	else if (d < T->data)//插入左边
	{
		T->left = Insert(T->left, d);
		if (getH(T->left) - getH(T->right) == 2)//平衡处理
		{
			if (d < T->left->data)
				T = sinR(T);
			else if (d > T->left->data)
				T = douLR(T);
		}
	}
	else if (d > T->data)//插入右边
	{
		T->right = Insert(T->right, d);
		if (getH(T->right) - getH(T->left) == 2)
		{
			if (d < T->right->data)
				T = douRL(T);
			else if (d > T->right->data)
				T = sinL(T);
		}
	}

	return T;
}

void levelOrder()//层序输出
{
	queue<Node *> Q;
	int flag = 1;//标记是否完全二叉树
	Q.push(T);
	cout << T->data;
	int cnt = 1;//统计输出的结点数

	while (!Q.empty())
	{
		Node *p = Q.front();
		Q.pop();

		if (p->left != NULL)
		{
			Q.push(p->left);
			cout << ' ' << p->left->data;
			cnt++;
		}
		else
		{
			if (cnt < N)//还没遍历完结点，则不是完全二叉树
				flag = 0;
		}

		if (p->right != NULL)
		{
			Q.push(p->right);
			cout << ' ' << p->right->data;
			cnt++;
		}
		else
		{
			if (cnt < N)
				flag = 0;
		}
	}

	if (flag == 1)
		cout << "\nYES\n";
	else
		cout << "\nNO\n";
}

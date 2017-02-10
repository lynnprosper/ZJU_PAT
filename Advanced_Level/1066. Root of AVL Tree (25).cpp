#include<iostream>
#include<algorithm>//使用max函数
using namespace std;

struct Node//二叉树结点
{
	Node() : left(NULL), right(NULL) {}//初始化
	int data;
	Node *left, *right;
};

int getH(Node *T);//取得树的高度
Node *singleLL(Node *T);//左单旋
Node *singleRR(Node *T);//右单旋
Node *doubleLR(Node *T);//左右双旋
Node *doubleRL(Node *T);//右左双旋
Node *Insert(Node *T, int d);//插入AVL树

/*
题意：
构建AVL树。
思路：
AVL算法题。直接读入数据，然后插入树，并调整。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N;
	Node *T = NULL;//根结点
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tem;
		cin >> tem;
		T = Insert(T, tem);
	}
	cout << T->data << endl;

	return 0;
}

int getH(Node *T)//递归取得树的高度
{
	if (T == NULL)//空时树高为0
		return 0;
	return (max(getH(T->left), getH(T->right)) + 1);
}

Node *singleLL(Node *T)//左单旋
{
	Node *A = T->right;
	T->right = A->left;
	A->left = T;
	return A;
}

Node *singleRR(Node *T)//右单旋
{
	Node *A = T->left;
	T->left = A->right;
	A->right = T;
	return A;
}

Node *doubleLR(Node *T)//左右双旋
{
	T->left = singleLL(T->left);
	T = singleRR(T);
	return T;
}

Node *doubleRL(Node *T)//右左双旋
{
	T->right = singleRR(T->right);
	T = singleLL(T);
	return T;
}

Node *Insert(Node *T, int d)//插入AVL树
{
	if (T == NULL)//空，则建立新结点，直接插入
	{
		T = new Node;
		T->data = d;
	}
	else if (d < T->data)//插入左边
	{
		T->left = Insert(T->left, d);
		if (getH(T->left) - getH(T->right) == 2)//树的调整
		{
			if (d < T->left->data)
				T = singleRR(T);//往右旋转调整
			else if (d > T->left->data)
				T = doubleLR(T);
		}
	}
	else if (d > T->data)//插入右边
	{
		T->right = Insert(T->right, d);
		if (getH(T->left) - getH(T->right) == -2)
		{
			if (d > T->right->data)//右边不平衡，往左旋转
				T = singleLL(T);
			else if (d < T->right->data)
				T = doubleRL(T);
		}
	}

	return T;
}

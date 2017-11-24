#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
	Node(int x) : data(x), left(NULL), right(NULL) {}
	int data;
	Node *left, *right;
};
Node *T = NULL;	//根结点

void Build(Node *&T, int x);	//***构建二叉搜索树
bool JudgeNode(Node *T);	//***判断条件4
int JudgeNum(Node *T);	//*** 判断条件5

/*
题意： 判断一棵二叉树是否红黑树。 树的遍历问题。
思路：
题目已经给出了判断条件，根据条件判断即可。
主要时条件4和5的判断。
1. 首先要建树了。
对于BST构建，原则上有两种。
传统的前序和中序建树。
另一种，由于BST的特殊性，即左边小于当前结点值，右边的大于当前结点值。
利用这一特性可以递归建树。
这里用第二种方便。
2.
判断条件4， 用递归判断即可。
3.
判断条件5， 同样递归判断，左树和右树的黑色结点数相等则符合。
已AC
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int N, k, tmp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		T = NULL;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &tmp);
			Build(T, tmp);//***构建二叉搜索树
		}

		if (T->data > 0 && JudgeNode(T) && JudgeNum(T) > -1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}

	return 0;
}

void Build(Node *&T, int x)//***构建二叉搜索树
{
	if (T == NULL)
	{
		T = new Node(x);
	}
	else if (abs(x) < abs(T->data))
	{
		Build(T->left, x);
	}
	else
	{
		Build(T->right, x);
	}

	return;
}

bool JudgeNode(Node *T)//***判断条件4
{
	if (T == NULL)
		return true;
	if (T->data < 0)
	{
		if (T->left != NULL && (T->left->data < 0))
			return false;
		if (T->right != NULL && (T->right->data < 0))
			return false;
	}

	return (JudgeNode(T->left) && JudgeNode(T->right));
}

int JudgeNum(Node *T)	
{
	if (T == NULL)
		return 0;
	
	int left = JudgeNum(T->left);	//***返回值-1 表示不符合， 大于0为黑色结点数
	int right = JudgeNum(T->right);
	if (left < 0 || right < 0 || left != right)
	{
		return -1;
	}
	else
	{
		if (T->data > 0)
			return (left + 1);
		else
			return left;
	}
}

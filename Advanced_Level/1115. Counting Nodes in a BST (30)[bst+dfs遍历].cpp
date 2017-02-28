#include<iostream>
using namespace std;

struct Node
{
	Node() : left(NULL), right(NULL) {}
	int data;
	Node *left, *right;
};
Node *T = NULL;//bst树的根
int cnt[1000] = { 0 };//记录某深度所在层的结点数
int maxn = -1;//记录最大深度

void Insert(Node *&t, int d);//构建bst树
void dfs(Node *nod, int deep);//递归获取树深并更新每层数目

/*
题意：
按照bst的原则构建bst树，然后输出倒数两层的结点数。
思路：
显然首先递归插入来建树。
然后树深可以用bfs或dfs。
dfs简捷些，然后递归的时候用一个计数器数组记录层深的结点数和最大树深就好了。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int elem;
		scanf("%d", &elem);
		Insert(T, elem);//建树
	}

	dfs(T, 0);//递归遍历
	printf("%d + %d = %d\n", cnt[maxn], cnt[maxn - 1], cnt[maxn] + cnt[maxn - 1]);

	return 0;
}

void Insert(Node *&t, int d)//构建bst树, 注意参数是指针的指针（要修改指针)
{
	if (t == NULL)//递归结束条件
	{
		t = new Node;
		t->data = d;
	}
	else if (d <= t->data)//插入左侧
		Insert(t->left, d);
	else//插入右侧
		Insert(t->right, d);

	return;
}

void dfs(Node *nod, int deep)//递归获取树深并更新每层数目
{
	if (nod == NULL)//递归终止
		return;

	dfs(nod->left, deep + 1);//递归左
	dfs(nod->right, deep + 1);//递归右
	cnt[deep]++;//累加
	if (deep > maxn)//更新最大树深
		maxn = deep;

	return;
}

#include<iostream>
#include<queue>
using namespace std;

const int MAX = 30;	//最大结点数
struct Btree	//结点结构体
{
	int data;
	Btree *left, *right;
};
int post[MAX] = {0};	//存储后序序列
int infix[MAX] = {0};	//存储中序序列
int N;

Btree *dfs(int pl, int pr, int il, int ir);	//dfs建树
void levelOrder(Btree *T);	//层序输出
void deleteTree(Btree *T);	//释放空间，考试时可不写，平时养成好习惯

/*
思路：
比较简单，先dfs递归利用给出的中序和后序的特点构建唯一的树，然后利用BFS层序输出。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> post[i];
	for(int i = 0; i < N; i++)
		cin >> infix[i];

	Btree *T = dfs(0, N-1, 0, N-1);
	//cout << 6 << endl;
	levelOrder(T);

	return 0;
}

Btree *dfs(int pl, int pr, int il, int ir)	//参数分别表示后序左、边界， 中序左、右边界
{
	if(pl > pr)	//递归结束条件
		return NULL;

	Btree *t = new Btree;
	t->data = post[pr];

	int root;
	for(int i = 0; i < N; i++)	//找出根结点在中序的位置
	{
		if(infix[i] == post[pr])
		{
			root = i;
			break;
		}
	}

	t->left = dfs(pl, pr-ir+root-1, il, root-1);		//递归左子树， 注意参数，不要写错了，可以在纸上模拟下
	t->right = dfs(pl+root-il, pr-1, root+1, ir);	//递归右子树
	return t;	//返回根结点
}

void levelOrder(Btree *T)	//利用BFS
{
	queue<Btree *> Q;
	Btree *t = T;
	Q.push(t);
	int cnt = 0;	//为了便于输出

	while(!Q.empty())
	{
		Btree *tem = Q.front();
		cnt++;
		if(tem->left)
			Q.push(tem->left);
		if(tem->right)
			Q.push(tem->right);

		if(cnt == 1)
			cout << tem->data;
		else
			cout << " " << tem->data;
		Q.pop();
	}
	cout << endl;
}

void deleteTree(Btree *T)
{
	if(T == NULL)
		return;
	deleteTree(T->left);
	deleteTree(T->right);
	deleteTree(T);
}

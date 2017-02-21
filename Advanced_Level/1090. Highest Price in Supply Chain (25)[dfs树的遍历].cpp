#include<iostream>
#include<vector>
#include<algorithm>//使用pow函数，用来求指数
using namespace std;

int level = 0, N;//分别为树的最大层次， 结点数
int cnt = 0;//同一层次的结点数
vector< vector<int> > G;//图的邻接表表示
void dfs(int root, int deep);//dfs递归求最大层次

/*
题意：
给出一颗树，求出树的最大层次及同层的结点数。
思路：
显然可以用dfs，每次递归，层次加1.
也可用bfs.
为求简便，用dfs。
已AC
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int root;//树的根
	double price, rate;//分别为初始价， 加价比率
	scanf("%d %lf %lf", &N, &price, &rate);
	G.resize(N);

	for (int i = 0; i < N; i++)//读入数据
	{
		int parent;//父结点编号
		scanf("%d", &parent);
		if (parent == -1)//找到了根结点
			root = i;
		else
			G[parent].push_back(i);//压入父结点的容器
	}

	dfs(root, 0);//递归求出层次level和个数cnt
	double max_price = price * pow((1 + rate / 100), double(level));//最高价
	printf("%.2f %d\n", max_price, cnt);

	return 0;
}

void dfs(int root, int deep)//dfs递归求最大层次
{
	if (G[root].empty())//表示到了叶子结点，递归结束
	{
		if (level < deep)//更新树深和个数cnt
		{
			level = deep;
			cnt = 1;
		}
		else if (level == deep)
			cnt++;

		return;
	}

	for (int i = 0; i < G[root].size(); i++)//递归子树
		dfs(G[root][i], deep + 1);
	return;
}

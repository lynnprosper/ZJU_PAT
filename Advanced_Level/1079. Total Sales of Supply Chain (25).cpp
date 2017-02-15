#include<iostream>
#include<vector>
using namespace std;

int N;//结点数
double price, r, sum = 0;//分别为价格， 比率， 总价
vector<int> pro;//存储叶子结点的产品数量
vector< vector<int> > G;//图的邻接表表示
void dfs(int sn, double price);//dfs递归，第一个参数是根结点

/*
题意：
给定一棵树，求叶子结点所代表的值的总和。
题目中的每一行表示该行的行号（从0开始）的子结点。第一个0表示该行行号
表示的结点是叶子结点。
思路：
dfs和bfs都可以。dfs简捷些。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %lf %lf", &N, &price, &r);
	pro.resize(N, 0);
	G.resize(N);

	for (int i = 0; i < N; i++)//读入数据
	{
		int cnt;
		scanf("%d", &cnt);
		if (cnt == 0)
			scanf("%d", &pro[i]);//存储该结点的产品数量
		else
		{
			for (int j = 0; j < cnt; j++)
			{
				int id;
				scanf("%d", &id);
				G[i].push_back(id);
			}
		}
	}

	dfs(0, price);//递归
	printf("%.1lf\n", sum);

	return 0;
}

void dfs(int sn, double price)
{
	if (G[sn].empty())//表示叶子结点
	{
		double tem = pro[sn] * price;//累计价钱
		sum += tem;
		return;
	}

	price *= (1 + r / 100.0);
	for (int i = 0; i < G[sn].size(); i++)//递归下一层
		dfs(G[sn][i], price);

	return;
}

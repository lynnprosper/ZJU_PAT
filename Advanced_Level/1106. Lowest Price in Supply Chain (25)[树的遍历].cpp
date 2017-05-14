#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > G;//树的邻接表表示
int cnt = 0;//最低价格的零售商数
int minDep = 0x7fffffff;//最小深度，初始为最大值

void dfs(int id, int depth);//深度搜索

/*
题意：给你一颗树，求出叶子节点的最小深度。
思路：
题意不难，用dfs或者bfs都可以。
为求简洁，这里用的dfs。
先把结点存储到二维数组里，从根结点开始递归遍历。
minDep记录最小深度，cnt记录个数。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N;
	double p, r;
	scanf("%d %lf %lf", &N, &p, &r);
	G.resize(N);
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int tmp;
			cin >> tmp;
			G[i].push_back(tmp);//存入每个孩子
		}
	}

	dfs(0, 0);
	double minPrice = p * pow((1 + r / 100), minDep);
	printf("%.4f %d\n", minPrice, cnt);

	return 0;
}

void dfs(int id, int depth)//dfs的常规写法
{
	if (depth > minDep)//剪枝优化
		return;

	if (G[id].size() == 0)
	{
		if (depth < minDep)
		{
			cnt = 1;
			minDep = depth;
		}
		else if (depth == minDep)
		{
			cnt++;
		}
	}
	else
	{
		for (int i = 0; i < G[id].size(); i++)
			dfs(G[id][i], depth + 1);
	}

	return;
}

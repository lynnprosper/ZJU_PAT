#include<iostream>
using namespace std;

const int MAX = 500;	//最大结点数
const int INF = 0x7FFFFFF;	//无穷大
int G[MAX][MAX];	//存储路径长度
int cost[MAX][MAX];	//存储费用
int path[MAX];	//存储上一个结点
int dist[MAX];	//存储源点到某点的距离
int min_cost[MAX];	//存储费用
int collect[MAX] = {0};	//表示某点已收录到最短路径中
int N, M, S, D;

void dijkstra();	//dijkstra函数
int Find_min();	//找到未收录的最小路径
void print(int d);	//递归输出函数

/*
题意：单源最短路径，路径相等则判断费用最小。比较简单。
思路：直接用dijkstra算法，同时把到达某点的上一个
结点存储在path里，用于输出路径。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> N >> M >> S >> D;
	for (int i = 0; i < N; i++)	//初始化
	{
		path[i] = -1;
		for (int j = 0; j < N; j++)
		{
			G[i][j] = INF;
			cost[i][j] = INF;
		}
		dist[i] = INF;
		min_cost[i] = INF;
	}

	for (int i = 0; i < M; i++)//读入数据
	{
		int c1, c2, len, expen;
		cin >> c1 >> c2 >> len >> expen;
		G[c1][c2] = G[c2][c1] = len;
		cost[c1][c2] = cost[c2][c1] = expen;
	}
	dijkstra();

	return 0;
}

void dijkstra()//dijkstra函数
{
	dist[S] = 0;
	min_cost[S] = 0;

	while(1)	//循环处理
	{
		int v = Find_min();
		if (v == -1)		//-1表示已全部查找完，跳出
			break;
		collect[v] = 1;

		for (int w = 0; w < N; w++)	//收录v后更新未收录的结点的状态
		{
			if(collect[w] == 0 && G[v][w] < INF)
			{
				if(dist[v] + G[v][w] < dist[w])
				{
					dist[w] = dist[v] + G[v][w];
					path[w] = v;
					min_cost[w] = min_cost[v] + cost[v][w];
				}
				else if (dist[v] + G[v][w] == dist[w])
				{
					if (min_cost[v] + cost[v][w] < min_cost[w])
					{
						min_cost[w] = min_cost[v] + cost[v][w];
						path[w] = v;
					}
				}
			}
		}
	}

	print(D);
	printf("%d %d\n", dist[D], min_cost[D]);

	return;
}

int Find_min()//找到未收录的最小路径
{
	int min_dist = INF;
	int min_id = -1;
	for (int i = 0; i < N; i++)
	{
		if(collect[i] == 0 && dist[i] < min_dist)
		{
			min_dist = dist[i];
			min_id = i;
		}
	}

	return min_id;
}

void print(int d)//递归输出函数
{
	if (path[d] == -1)
	{
		printf("%d ", d);
		return;
	}
	print(path[d]);
	printf("%d ", d);

	return;
}

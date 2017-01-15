#include<iostream>
#include<algorithm>	//使用max();
using namespace std;

const int INF = 65535;	//表示不可达；
const int MAX = 500;
int G[MAX][MAX];	//图的邻接矩阵表示；
int dist[MAX];	//源点到某点的路径长度；
int path_cnt[MAX] = {0};	//路径数；
int team[MAX];	//团队数；
int sum[MAX];	//汇集的团队总数；
int collected[MAX] = {0};	//flag标志；
int N, M, s, d;

void dijkstra(int s);
int FindMin();	//寻找未收录点的最小边权值。

//思路：可用DFS, 或者diskstra, dfs简单些;
int main()
{
	//freopen("in.txt", "r", stdin);
	int i, j;
	cin >> N>> M>> s>> d;

	for(i = 0; i < N; i++)	//初始化
	{
		cin >> team[i];
		sum[i] = team[i];
		for(j = 0; j < N; j++)
			G[i][j] = INF;
	}
	for(i = 0; i < M; i++)	//构建图；
	{
		int si, di, len;
		cin >> si >>di >>len;
		G[si][di] = G[di][si] = len;
	}
	for(i = 0; i < N; i++)
	{
		dist[i] = G[s][i];
		if(dist[i] < INF)	//表示路径直接可达；
			path_cnt[i] = 1;
	}

	dijkstra(s);
	if(s != d)
		cout << path_cnt[d] << ' ' << sum[d]+sum[s] <<endl;	//sum里不包含源点的队数；
	else
		cout << 1 << ' ' << sum[s] <<endl;	//目的地是起点时；

	return 0;
}
int FindMin()	//寻找未收录点的最小边权值。
{
	int v, min_v = 0, min_dist;
	min_dist = INF;
	for(v = 0; v < N; v++)
	{
		if(min_dist > dist[v] && collected[v] == 0)
		{
			min_dist = dist[v];
			min_v = v;
		}
	}

	return min_v;
}

void dijkstra(int s)
{
	int v, w;
	collected[s] = 1;
	dist[s] = 0;
	path_cnt[s] = 1;

	while(1)
	{
		v = FindMin();
		if(v == d)
			break;
		collected[v] = 1;

		for(w = 0; w < N; w++)
		{
			if(collected[w] == 0 && G[v][w] < INF)
			{
				if(path_cnt[w] == 0)
					path_cnt[w] = 1;
				if(dist[w] > dist[v] + G[v][w])
				{
					dist[w] = dist[v] + G[v][w];
					path_cnt[w] = path_cnt[v];
					sum[w] = sum[v] + team[w];
				}
				else if(dist[w] == dist[v] + G[v][w])
				{
					path_cnt[w] += path_cnt[v];
					sum[w] = max(sum[w], sum[v] + team[w]);
				}
			}
			
		}
	}
}

#include<iostream>
#include<map>
#include<string>
using namespace std;

const int Max = 200 + 5;//最大结点数
const int INF = 0x7FFFFFFF;//表示无穷大
int G[Max][Max];//图的邻接矩阵表示法
int collect[Max] = { 0 };//记录某点是否被收录
int path[Max];//存储最短路径上的结点号
int dist[Max];//到某点的最短路径长度
int happy[Max] = { 0 };//记录每个点的幸福指数
int sum_happy[Max] = { 0 };//最短路径上的总指数
int route[Max] = { 0 };//到某点的路径条数
int cnt[Max] = { 0 };//记录到某点的路径上的点数，不含起点
int N, K;//分别为结点数， 路径数
map<string, int> id;//字符串映射成数字
map<int, string> name;//数字映射成字符串

int findMin();//找出未收录的最小权值
void dijkstra(int start);//dijkstra经典算法
void print(int num);//递归逆序打印路径

/*
题意：
单源最短路问题，同时要输出路径。
思路：
可以用dijkstra，用path记录路径。
也可以dfs，回溯剪枝。
或者两者结合，dijkstra找出最短路长度，再dfs.
我用的第一种方法。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	string s, d;//起点，终点
	cin >> N >> K >> s;
	id[s] = 0;//起点映射为0
	name[0] = s;

	for (int i = 0; i < N; i++)//图的初始化
	{
		for (int j = 0; j < N; j++)
			G[i][j] = INF;
		path[i] = -1;
	}

	for (int i = 1; i < N; i++)//读入数据
	{
		int val;//幸福指数
		cin >> s >> val;
		id[s] = i;
		name[i] = s;
		happy[i] = val;
	}

	for (int i = 0; i < K; i++)
	{
		int wgt;//权值
		cin >> s >> d >> wgt;
		int s1, d1;
		s1 = id[s];
		d1 = id[d];
		G[s1][d1] = G[d1][s1] = wgt;
	}

	dijkstra(0);//最短路经典算法
	int end = id["ROM"];//终点
	printf("%d %d %d %d\n", route[end], dist[end], sum_happy[end],
		sum_happy[end] / (cnt[end] + 1));//分别为最短路的路径数， 路径长度，总指数，平均指数
	print(end);//打印路径
	cout << endl;

	return 0;
}

int findMin()//找出未收录的最小权值
{
	int min_id = -1;
	int min_val = INF;
	for (int i = 0; i < N; i++)
	{
		if (collect[i] == 0 && dist[i] < min_val)
		{
			min_val = dist[i];
			min_id = i;
		}
	}

	return min_id;
}

void dijkstra(int start)//dijkstra经典算法
{
	for (int i = 0; i < N; i++)//初始化
	{
		dist[i] = G[start][i];
		sum_happy[i] = happy[i];
	}

	route[start] = 1;//起点的路径条数初始为1, 0不可以。
	dist[start] = 0;//起点到起点为0

	while (1)
	{
		int v = findMin();
		if (v == -1)//循环终止
			break;

		collect[v] = 1;
		for (int w = 0; w < N; w++)
		{
			if (collect[w] == 0 && G[v][w] < INF)
			{
				if ((dist[v] + G[v][w]) < dist[w])//找到最短路
				{
					cnt[w] = cnt[v] + 1;//到w的路径上的结点数加1
					dist[w] = dist[v] + G[v][w];
					route[w] = route[v];//更新路径条数
					sum_happy[w] = sum_happy[v] + happy[w];
					path[w] = v;//表示到w的上一个结点是v
				}
				else if ((dist[v] + G[v][w]) == dist[w])//存在多个最短路
				{
					route[w] += route[v];//更新路径条数
					if (sum_happy[w] < (sum_happy[v] + happy[w]))//存在最大幸福指数的路径
					{
						path[w] = v;
						cnt[w] = cnt[v] + 1;
						sum_happy[w] = sum_happy[v] + happy[w];
					}
					else if ((sum_happy[w] == sum_happy[v] + happy[w])
						&& (cnt[w] > (cnt[v] + 1)))//存在最大的平均指数的路径
					{
						path[w] = w;
						cnt[w] = cnt[v] + 1;
					}
				}
			}	
		}
	}

	return;
}

void print(int num)//递归逆序打印路径
{
	if (num == -1)//递归结束条件
	{
		cout << name[0];
		return;
	}

	print(path[num]);
	cout << "->" << name[num];
}

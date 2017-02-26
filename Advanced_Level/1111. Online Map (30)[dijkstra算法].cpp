#include<iostream>
#include<vector>
using namespace std;

const int Max = 500;//最大结点数
const int INF = 0x7FFFFFFF;//无穷大
int N, M, s, d;//分别为结点数， 路径数， 起点，目的地。
int len[Max][Max], dtime[Max][Max];//分别为路径长度的图和时间花费的图
int collected[Max] = { 0 };//记录是否已经遍历
int path[Max];//记录路径
int dist[Max];//记录起点到某点的花费

int findMin();//找出未收录的最小长度
void dijkstra_len();//对路径长度图进行dijkstra
void dijkstra_time();//对时间花费图进行dijkstra
void generatePath(vector<int> &v, int index);//生成最短路径
void print(vector<int> &v);//输出路径

/*
题意：
给定图含有时间及距离。
求单源最短路径。
要求：
1. 输出距离最短路径。存在多条时，选择时间最短的。
2. 输出时间最短的路径。存在多条时，选择结点数最少的。

思路：
题意不难。显然dijkstra算法。
对距离和时间分别dijkstra就可以了。
我写了两个dijkstra函数（代码比较长，好在第二个复制改了下）。
也可以写一个，然后调用不同参数，这样代码少。都可以。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)//图进行初始化
	{
		for (int j = 0; j < N; j++)
			len[i][j] = dtime[i][j] = INF;
	}

	for (int i = 0; i < M; i++)//读入数据
	{
		int start, end, flag, t_len, t_time;
		scanf("%d %d %d %d %d", &start, &end, &flag, &t_len, &t_time);
		
		if (flag == 0)//说明是双向
		{
			len[start][end] = len[end][start] = t_len;
			dtime[start][end] = dtime[end][start] = t_time;
		}
		else//单向路径
		{
			len[start][end] = t_len;
			dtime[start][end] = t_time;
		}
	}

	scanf("%d %d", &s, &d);//起点， 终点
	dijkstra_len();//对路径长度图进行dijkstra
	vector<int> timepath, lenpath;//分别存储两个输出的路径
	int lenWgt = dist[d];//距离总开销
	generatePath(lenpath, d);//生成路径

	dijkstra_time();
	int timeWgt = dist[d];
	generatePath(timepath, d);

	if (timepath == lenpath)//相同路径，输出一个即可
	{
		printf("Distance = %d; Time = %d: ", lenWgt, timeWgt);
		print(timepath);
	}
	else
	{
		printf("Distance = %d: ", lenWgt);
		print(lenpath);
		printf("Time = %d: ", timeWgt);
		print(timepath);
	}

	return 0;
}

void dijkstra_len()//对路径长度图进行dijkstra
{
	int total[Max];//记录到达某点时的总时间
	for (int i = 0; i < N; i++)//初始化
	{
		total[i] = dtime[s][i];
		dist[i] = len[s][i];
		path[i] = -1;//这里的值是存储父结点
		collected[i] = 0;
	}
	dist[s] = 0;
	total[s] = 0;
	collected[s] = 1;

	while (1)//经典算法
	{
		int v = findMin();
		if (v == -1)
			break;

		collected[v] = 1;
		for (int w = 0; w < N; w++)
		{
			if (collected[w] == 0 && len[v][w] < INF)
			{
				if ((dist[v] + len[v][w]) < dist[w])
				{
					dist[w] = dist[v] + len[v][w];
					path[w] = v;
					total[w] = total[v] + dtime[v][w];
				}
				else if ((dist[v] + len[v][w]) == dist[w])
				{
					if ((total[v] + dtime[v][w]) < total[w])
					{
						path[w] = v;
						total[w] = total[v] + dtime[v][w];
					}
				}
			}
		}
	}

	return;
}

void dijkstra_time()//对时间花费图进行dijkstra
{
	int cnt[Max] = { 0 };//记录到达某点的总结点数
	for (int i = 0; i < N; i++)
	{
		dist[i] = dtime[s][i];
		path[i] = -1;
		collected[i] = 0;
	}
	dist[s] = 0;
	collected[s] = 1;

	while (1)
	{
		int v = findMin();
		if (v == -1)
			break;

		collected[v] = 1;
		for (int w = 0; w < N; w++)
		{
			if (collected[w] == 0 && dtime[v][w] < INF)
			{
				if ((dist[v] + dtime[v][w]) < dist[w])
				{
					dist[w] = dist[v] + dtime[v][w];
					path[w] = v;
					cnt[w] = cnt[v] + 1;
				}
				else if ((dist[v] + dtime[v][w]) == dist[w])
				{
					if ((cnt[v] + 1) < cnt[w])
					{
						path[w] = v;
						cnt[w] = cnt[v] + 1;
					}
				}
			}
		}
	}

	return;
}

int findMin()//找出未收录的最小长度
{
	int min_val = INF;
	int min_id = -1;
	for (int i = 0; i < N; i++)
	{
		if (collected[i] == 0 && dist[i] < min_val)
		{
			min_val = dist[i];
			min_id = i;
		}
	}

	return min_id;//-1表dijkstra算法结束
}

void generatePath(vector<int> &v, int index)//递归把结点压入容器
{
	if (index == -1)
	{
		v.push_back(s);
		return;
	}

	generatePath(v, path[index]);
	v.push_back(index);
	return;
}

void print(vector<int> &v)//输出路径
{
	for (int i = 0; i < v.size(); i++)
	{
		if (i != 0)
			printf(" -> ");
		printf("%d", v[i]);
	}
	printf("\n");
}

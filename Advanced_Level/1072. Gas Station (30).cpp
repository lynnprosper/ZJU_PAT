#include<iostream>
#include<string>
#include<sstream>//使用字符串流，用于字符串转换数字id
using namespace std;

const int INF = 0x7FFFFFF;//表示无穷大
const int Max = 1000 + 15;//房子和站点之和的最大数目
int N, M, K, Ds, A;//分别为房子，站点，路径数， 站点距房子的最大距离，总结点数
int G[Max][Max];//图的邻接矩阵表示
int dist[Max];//源点到各个房子的最短路径
int collected[Max] = { 0 };//dijkstra算法里的标记位，表示是否收录某点

int Toid(string &s);//转换成编号
int Findmin();//未收录的最小路径
void dijkstra(int s);

/*
题意：
选址问题。在备选站点中选出到各个房子的最短路径最大（在可及范围内）的站点。
若有多个，选取最短路平均值最小的，再次是最小id编号。
思路：
显然，要先求出站点到房子的最短路，即单源最短路径问题。dijkstra算法。
要解决的问题：
1. 站点编号不是数字，需要进行转换成数字编号。大小从房子数往后一次排列。
2. dijkstra后的每个站点，得出当前最小的最短路，要判断出最大的值，同时更新
平均值。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	cin >> N >> M >> K >> Ds;
	A = N + M;
	for (int i = 1; i <= A; i++)//为便于处理，从1开始，下同
	{
		for (int j = 1; j <= A; j++)
			G[i][j] = INF;//初始化为无穷大
	}

	for (int i = 0; i < K; i++)
	{
		string sn, dn;
		int wgt, si, di;
		cin >> sn >> dn >> wgt;
		si = Toid(sn);//转换成数字id
		di = Toid(dn);
		G[si][di] = G[di][si] = wgt;
	}

	double min_average = INF;//最小平均值
	double max_mindist = -1;//最大的最短路
	int flag, gid;//分别为标记，站点编号
	double sum;//所有最短路之和
	for (int i = 1; i <= M; i++)//循环遍历
	{
		int sta_id = i + N;
		dijkstra(sta_id);

		sum = 0;
		flag = 1;
		int cur_min = INF;//当前站点的最短路
		for (int i = 1; i <= N; i++)
		{
			if (dist[i] > Ds)
			{
				flag = 0;//表示超出了站点的可及范围，直接舍弃
				break;
			}
			sum += dist[i];
			if (dist[i] < cur_min)
				cur_min = dist[i];
		}

		if (flag == 1)
		{
			if (cur_min > max_mindist)//更新最大的最短路
			{
				max_mindist = cur_min;
				min_average = sum / N;
				gid = sta_id;
			}
			else if (cur_min == max_mindist)
			{
				if (sum / N < min_average)
				{
					gid = sta_id;
					min_average = sum / N;
				}
			}
		}
	}

	if (max_mindist == -1)//输出
		printf("No Solution\n");
	else
	{
		printf("G%d\n%.1f %.1f\n", gid - N, max_mindist, min_average);
	}

	return 0;
}

int Toid(string &s)
{
	int id;
	if (s[0] == 'G')
	{
		s.erase(0, 1);//删除字符G
		stringstream ss(s);
		ss >> id;
		id = id + N;
	}
	else
	{
		stringstream ss(s);
		ss >> id;
	}
	
	return id;
}

int Findmin()//未收录的最小路径
{
	int min_dist, min_id = 0;
	min_dist = INF;
	for (int v = 1; v <= A; v++)
	{
		if (dist[v] < min_dist && collected[v] == 0)
		{
			min_dist = dist[v];
			min_id = v;
		}
	}

	return min_id;
}

void dijkstra(int s)//dijkstra经典算法
{
	for (int i = 1; i <= A; i++)
	{
		collected[i] = 0;
		dist[i] = G[s][i];
	}
	collected[s] = 1;
	dist[s] = 0;

	while (1)
	{
		int v = Findmin();
		if (v == 0)
			break;
		collected[v] = 1;

		for (int w = 1; w <= A; w++)
		{
			if (collected[w] == 0 && G[v][w] < INF)
			{
				if (dist[w] > (dist[v] + G[v][w]))
					dist[w] = dist[v] + G[v][w];
			}
		}
	}

	return;
}

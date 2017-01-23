#include<iostream>
#include<vector>
using namespace std;

const int INF = 65535;	//无穷大
const int MAX = 505;	//站点最大数目
int G[MAX][MAX] = {0};	//图的邻接矩阵表示
int station[MAX] = {0};	//存储每个站点的自行车数目
int C, N, S, M, perfect;	//分别表示站点容量， 站点数， 需要调整站点， 路径条数， 最佳自行车数目
vector<int> min_path, cur_path;	//分别表示最优路径， 目前路径的容器
int min_send = INF;	//最小调来车子数
int min_back = INF;	//最小调回数
int cur_send = 0;	//目前的调度数
int cur_back = 0;
int visited[MAX] = {0};	//表示站点是否访问， 1为访问
int min_len = INF;	//最优WPL
int cur_len = 0;

void dfs(int point);	//递归

/*
题意：
找出一条最优路径， 条件：min_len > min_send > min_back， 优先级依次降低。
在优化目的站点的过程中，同时优化经过的每个站点，注意这是单向的。
比如， perfect = 5， 1号 3， 2号 7， 不会把2号的调给1，此时min_send = 2;
思路：
图的问题，比较复杂。
可以用dijkstra, 此处bfs不行。
为了简便， 采用dfs+dp(动态规划）的混合算法。
在dfs的时候不断更新最优状态。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> C >> N >> S >> M;
	perfect = C/2;
	for(int i = 1; i <= N; i++)	//读入数据
		cin >> station[i];

	for(int i = 0; i < M; i++)
	{
		int start, end, weight;
		cin >> start >> end >> weight;
		G[start][end] = G[end][start] = weight;
	}
	dfs(0);	//dfs遍历

	cout << min_send << " " << 0;	//容器中的路径不含起点0；
	for(unsigned i = 0; i < min_path.size(); i++)
		cout << "->" << min_path[i];
	cout << " " << min_back << endl;

	return 0;
}

void dfs(int point)
{
	visited[point] = 1;	//访问该点，置为1
	if(cur_len > min_len)	//大于，直接返回
		return;

	if(point == S)	//访问到了目的地
	{
		if(cur_len < min_len)	//小于表示目前最佳，更新状态， dp思想
		{
			min_path = cur_path;
			min_len = cur_len;
			min_send = cur_send;
			min_back = cur_back;
		}
		else if(cur_len == min_len)	//相等，按照题意的优先级分情况讨论
		{
			if(cur_send < min_send)	//目前的调度最小， 更新状态，下同。
			{
				min_path = cur_path;
				min_send = cur_send;
				min_back = cur_back;
			}
			else if(cur_send == min_send && cur_back < min_back)
			{
				min_path = cur_path;
				min_back = cur_back;
			}
		}

		return;
	}

	for(int i = 1; i <= N; i++)	//还未访问到目的地，循环dfs
	{
		if(visited[i] == 0 && G[point][i])
		{
			int last_send = cur_send;	//上一个站点的状态，用来暂存，以便弹出该点时，恢复状态
			int last_back = cur_back;
			cur_len += G[point][i];	//累加
			cur_path.push_back(i);	//压入路径容器

			if(cur_back + station[i] < perfect)	//分情况更新调度车子数目
			{
				cur_send += perfect - cur_back - station[i];
				cur_back = 0;
			}
			else
			{
				cur_back += station[i] - perfect;
			}

			dfs(i);	//dfs下一个
			cur_path.pop_back();	//从dfs(i)返回，弹出结点i；
			visited[i] = 0;	//置为未访问
			cur_len -= G[point][i];	//恢复原有状态
			cur_send = last_send;
			cur_back = last_back;
		}
	}

	return;
}

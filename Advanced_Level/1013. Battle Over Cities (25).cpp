#include<iostream>
#include<cstring>	//memset()
using namespace std;

const int MAX = 1000;
int G[MAX][MAX] = {0};	//图的邻接矩阵表示
int visited[MAX] = {0};	//1表示某点被访问过
int N, M, K;

void dfs(int start);	//dfs

/*
思路：
题意是有一个图，某个点抹掉后，求剩下可以构成几个子图，然后减去1就是恢复道路条数。
基础算法题。
可以用DFS, BFS, 并查集。
这里DFS最简单。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> N >> M >> K;	//读入数据；
	for(int i = 0; i < M; i++)
	{
		int s, d;
		cin >> s >> d;
		G[s][d] = G[d][s] = 1;
	}

	for(int i = 0; i < K; i++)	//处理数据；
	{
		memset(visited, 0, sizeof(visited));	//每次需要初始化0；
		int occupied;	//被占用的点；
		int count = 0;	//记录子图数；
		cin >> occupied;
		visited[occupied] = 1;	//置为1，表示以后dfs不会访问该点，即该点丢掉。

		for(int j = 1; j <= N; j++)
		{
			if(visited[j] == 0)	//未访问，进行dfs
			{
				count++;
				dfs(j);
			}
		}
		cout << count-1 << endl;
	}

	return 0;
}

void dfs(int start)	//dfs
{
	visited[start] = 1;
	for(int i = 1; i <= N; i++)
	{
		if(visited[i] == 0 && G[start][i] == 1)
			dfs(i);
	}
}

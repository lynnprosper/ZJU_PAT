#include<iostream>
#include<cstring>	//使用memset()
#include<vector>
using namespace std;

#define MAX 10001	//结点数最大值
vector<int> G[MAX];	//图的邻接表表示
int visited[MAX] = {0};//表示结点是否访问
int N = 0;
int cnt = 0;	//保存连通分量数目
int max_deep = 0;	//最大深度
int cur_root;	//dfs开始的根结点
vector<int> root;	//保存最大深度的根结点

void dfs(int start, int cur_deep);//dfs找出最大深度的根结点
void dfs_components(int start);	//dfs找出连通分量数目

/*
题意：
先判断是否连通，连通则找出某结点开始能到达的最大深度；
否则，输出多少个连通分量。
思路：
题目给出N-1个边，可排除N个结点形成的环。
找出连通分量可用dfs, 也可以并查集，通用是并查集。
最大深度可以bfs，也可以dfs。
注：图是稀疏图，用邻接矩阵会超时。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d", &N);
	for(int i = 1; i < N; i++)	//读入数据
	{
		int s, d;
		scanf("%d %d", &s, &d);
		G[s].push_back(d);
		G[d].push_back(s);
	}
	
	for(int i = 1; i <= N; i++)	//遍历每个结点，找出连通数目
	{
		if(visited[i] == 0)
		{
			cnt++;	//结点未访问，表示一个新的连通分量
			dfs_components(i);
		}
	}

	if(cnt > 1)
		printf("Error: %d components\n", cnt);
	else	//是连通图
	{
		for(int i = 1; i <= N; i++)	//循环遍历每个结点
		{
			memset(visited, 0, sizeof(visited));	//初始化为0
			cur_root = i;	//保存每次遍历的起点
			dfs(i, 1);
		}

		for(unsigned i = 0; i < root.size(); i++)	//输出
			printf("%d\n", root[i]);
	}

	return 0;
}

void dfs(int start, int cur_deep)//dfs找出最大深度的根结点
{
	visited[start] = 1;//已访问该点
	if(cur_deep > max_deep)	//更新最大深度
	{
		max_deep = cur_deep;
		root.clear();	//清空容器
		root.push_back(cur_root);
	}
	else if(cur_deep == max_deep)	//相等的情况
	{
		if(root[root.size()-1] != cur_root)	//该起点未加入容器
			root.push_back(cur_root);
	}

	for(unsigned i = 0; i < G[start].size(); i++)	//循环dfs
	{
		int next = G[start][i];
		if(visited[next] == 0)
			dfs(next, cur_deep+1);
	}

	return;
}

void dfs_components(int start)//dfs找出连通分量数目
{
	visited[start] = 1;
	for(unsigned i = 0; i < G[start].size(); i++)	//循环dfs
	{
		int next = G[start][i];
		if(visited[next] == 0)
			dfs_components(next);
	}

	return;
}

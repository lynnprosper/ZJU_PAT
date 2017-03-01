#include<iostream>
#include<vector>
#include<cstring>//使用memset函数
using namespace std;

const int Max = 200 + 5;//最大结点数
int G[Max][Max] = { 0 };//图的邻接矩阵表示，初始化为0，即未连通
int N;//结点数
int visited[Max];//记录是否访问过

int Judge();//判断是否哈密顿回路

/*
题意：
给你一个图以及很多路径，判断每个路径是否哈密顿回路。
思路：
图的遍历题。
首先要清楚哈密顿回路：
1.闭合路径，首尾结点相同。
2.路径结点数 = 图的结点数+1， 即含有图中所有顶点
3.除了首尾，每个点必须且只能访问一次。
4.相邻点存在边。

清楚特点就好办了，遍历的时候判断条件就好了。
已AC。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int s, d;
		scanf("%d %d", &s, &d);
		G[s][d] = G[d][s] = 1;//1表示有边
	}

	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		if (Judge() == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

int Judge()//判断是否哈密顿回路
{
	int n;
	scanf("%d", &n);
	vector<int> gra(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &gra[i]);

	if ((gra[0] != gra[n - 1]) || (n-1 != N))//与条件1，2不符
		return 0;
	memset(visited, 0, sizeof(visited));//初始化0
	for (int i = 0; i < n - 1; i++)
	{
		if (G[gra[i]][gra[i + 1]] == 1 && visited[gra[i]] == 0)//有边且未访问
			visited[gra[i]] = 1;
		else
			return 0;
	}

	return 1;
}

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>//使用memset函数
using namespace std;

const int Max = 1001;//最大用户数
int N, L;//分别为用户数， 层数
vector<int> G[Max];//图的邻接表表示
int flag[Max] = { 0 };//标记是否已转发

int bfs(int st);//广度优先搜索

/*
题意：求一个微博的最大转发量（给定层数的条件下）。
思路：
图的遍历问题
BFS算法。bfs的时候记录深度。
数据结构用邻接表（稀疏矩阵）。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &L);

	for (int i = 1; i <= N; i++)
	{
		int t_num;
		scanf("%d", &t_num);
		for (int j = 0; j < t_num; j++)//读入数据
		{
			int si;
			scanf("%d", &si);
			G[si].push_back(i);
		}
	}

	int K;//查询数目
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int st;
		scanf("%d", &st);
		printf("%d\n", bfs(st));//输出
	}

	return 0;
}

int bfs(int st)//广度优先搜索，参数是起点
{
	queue<int> Q;
	int last = st;//记录当前层的最后一个结点
	int cur_last, cnt = 0;//当前的结点， 转发数
	int deep = 0;//深度
	Q.push(st);
	flag[st] = 1;//自己不能转发

	while (!Q.empty())
	{
		if (deep == L)//循环结束条件
			break;
		
		int now = Q.front();//当前结点
		Q.pop();
		for (int i = 0; i < G[now].size(); i++)
		{
			if (flag[G[now][i]] == 0)//该用户未转发
			{
				cnt++;
				Q.push(G[now][i]);
				flag[G[now][i]] = 1;
				cur_last = G[now][i];
			}
		}

		if (now == last)//更新深度
		{
			last = cur_last;
			deep++;
		}
	}
	
	memset(flag, 0, sizeof(flag));//初始化为0
	return cnt;
}

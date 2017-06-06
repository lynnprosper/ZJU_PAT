#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MaxN = 10000;
int stops[MaxN][MaxN] = { 0 };//存储两点之间的所属线路
vector<int> vs[MaxN];//邻接表的二维数组表示
int visited[MaxN] = { 0 };//某点是否已经访问
int minDep, minTrans, s, d;//分别为最小站点数，最小换乘，起点和终点
vector<int> path, curPath;//分别为存储结果的路径及dfs的临时路径

void dfs(int start, int depth, int trans, int lastLine);//dfs递归

/*
题意：给出一个图，求起点到终点的最短路径。单源最短路径问题。
思路：
虽然求最短路，不过有要求，同时是最小换乘。
这样该怎么好呢。
求最短路，无外乎dfs和dijkstra。显然，对于该题，
我们不需要遍历某点到所有点的最短路。那就用dfs算法了。
为了判断换乘的问题，我们单独把两点的所属线路存储到数组stops里。
在dfs的时候进行判断即可。
dfs时，同时要进行剪枝优化和回溯。
输出结果就简单了。
已AC.
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)//读入数据
	{
		int M, pre;//pre存储上一个结点
		scanf("%d %d", &M, &pre);
		for (int j = 1; j < M; j++)
		{
			int node;
			scanf("%d", &node);
			vs[node].push_back(pre);
			vs[pre].push_back(node);
			stops[pre][node] = stops[node][pre] = i;
			pre = node;
		}
	}

	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d", &s, &d);

		minDep = minTrans = 0x7fffffff;//初始为最大
		path.clear();
		curPath.clear();
		memset(visited, 0, sizeof(visited));
		dfs(s, 0, 0, 0);

		printf("%d\n", minDep);
		int lastLine = stops[path[0]][path[1]];//上一条线路
		int lastStop = path[0];//上一个乘车点

		int j = 1;
		while (1)
		{
			while (j < path.size() && stops[path[j - 1]][path[j]] == lastLine) j++;//同一线路，一直遍历
			printf("Take Line#%d from %04d to %04d.\n", lastLine, lastStop, path[j - 1]);
			if (j == path.size())//遍历结束
				break;
			lastStop = path[j - 1];//更新上一个乘车点
			lastLine = stops[path[j - 1]][path[j]];//更新上一条线路
		}
	}

	return 0;
}


void dfs(int start, int depth, int trans, int lastLine)//dfs递归
{
	if (depth > minDep)//剪枝优化，下面的不需要继续递归遍历了
		return;

	visited[start] = 1;//访问过该点了，置1
	curPath.push_back(start);//压入临时路径

	if (start == d)//到达终点
	{
		if (depth < minDep || (depth == minDep && trans < minTrans))
		{
			minDep = depth;
			minTrans = trans;
			path.clear();
			path = curPath;
		}
	}

	for (auto it = vs[start].begin(); it != vs[start].end(); it++)//遍历下面的所有点
	{
		if (visited[*it] == 0)
		{
			if (stops[start][*it] != lastLine)//此处，换乘数可以加1了
				dfs(*it, depth + 1, trans + 1, stops[start][*it]);
			else
				dfs(*it, depth + 1, trans, lastLine);
		}
	}

	visited[curPath.back()] = 0;//到这里是回溯回来，恢复为未访问
	curPath.pop_back();//同时弹出该点
}

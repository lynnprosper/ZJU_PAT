#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > G;//图的邻接表表示法
int N;//总结点数
int visited[500+5] = { 0 };//判断是否访问过下标表示的结点
int cnt = 0;//统计连通图中的结点数

void dfs(int start);//递归遍历连通图

/*
题意：给出一个图，判断是否欧拉回路。
思路：
其实这题不懂欧拉回路的也没关系，题目已经给出了判断条件。
即：
1.连通图且所有结点的度都是偶数，是欧拉回路。
2.连通图且只有两个点的度是奇数，是半欧拉。
3.剩下的都不是欧拉回路。
根据条件，思路也就有了。
图可以用邻接矩阵或者邻接表表示。
这里用邻接表表示方便些。因为邻接表中的头结点的容量就是度。

首先用dfs判断是否连通。
然后判断度就可以了
已AC。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int M;
	cin >> N >> M;
	G.resize(N + 1);
	for (int i = 0; i < M; i++)//读入数据
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int oddCnt = 0;//奇数度的结点数目
	for (int i = 1; i <= N; i++)
	{
		if (i != 1)
			cout << ' ';
		cout << G[i].size();

		if (G[i].size() % 2 != 0)
			oddCnt++;
	}
	
	dfs(1);
	if (cnt == N)//表示连通
	{
		if (oddCnt == 0)
			cout << "\nEulerian" << endl;
		else if (oddCnt == 2)
			cout << "\nSemi-Eulerian" << endl;
		else
			cout << "\nNon-Eulerian" << endl;
	}
	else
		cout << "\nNon-Eulerian" << endl;

	return 0;
}

void dfs(int start)//递归遍历连通图
{
	visited[start] = 1;
	cnt++;
	for (int i = 0; i < G[start].size(); i++)
	{
		if (visited[G[start][i]] == 0)
			dfs(G[start][i]);
	}

	return;
}

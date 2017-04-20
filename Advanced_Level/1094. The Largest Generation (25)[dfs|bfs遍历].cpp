#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > family;//邻接表表示树
vector<int> levels;
int maxNum = 0;
int maxLevel = 0;

void dfs(int index, int level);//深度搜索优先

/*
题意：给出一棵树，找出某层最多的结点数。
思路：比较简单，用DFS或BFS遍历即可。
DFS简洁，这里用的DFS。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	family.resize(N + 1);
	levels.resize(N + 1, 0);
	for (int i = 0; i < M; i++)//构建邻接表
	{
		int parent, childNum, child;
		cin >> parent >> childNum;
		for (int j = 0; j < childNum; j++)
		{
			cin >> child;
			family[parent].push_back(child);
		}
	}

	dfs(1, 1);

	cout << maxNum << ' ' << maxLevel << endl;

	return 0;
}

void dfs(int index, int level)
{
	levels[level]++;
	if (levels[level] > maxNum)//判断最值。
	{
		maxNum = levels[level];
		maxLevel = level;
	}

	for (int i = 0; i < family[index].size(); i++)//递归遍历
	{
		dfs(family[index][i], level + 1);
	}
	
	return;
}

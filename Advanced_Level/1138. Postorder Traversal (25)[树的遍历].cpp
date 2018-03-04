#include<iostream>
#include<vector>
using namespace std;

int N, flag = 0;
vector<int> pre, ino, re;

void dfs(int pl, int pr, int nl, int nr);
int find_pos(int x, int nl, int nr);
/*
题意：给出前序和中序， 输出后序的第一个元素。
思路：
写个递归，在遍历到第一个元素后，直接返回退出就好了。
已AC。
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d", &N);
	pre.resize(N);
	ino.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &pre[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &ino[i]);
	dfs(0, N - 1, 0, N - 1);

	return 0;
}

void dfs(int pl, int pr, int nl, int nr)
{
	if (flag != 0 || pl > pr)	//返回退出
		return;

	int pos = find_pos(pre[pl], nl, nr);
	dfs(pl + 1, pos - nl + pl, nl, pos - 1);
	dfs(pos - nl + pl + 1, pr, pos + 1, nr);
	if (flag == 0)
	{
		printf("%d\n", pre[pl]);
		flag = 1;
	}
	
	return;
}

int find_pos(int x, int nl, int nr)
{
	for (int i = nl; i <= nr; i++)
	{
		if (ino[i] == x)
			return i;
	}

	return 0;
}

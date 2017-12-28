#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500;
int G[MAX][MAX] = { 0 };
int P[MAX] = { 0 };
int vis[MAX] = { 0 };

int S, D, N, M;
int mlen = 0x7ffffff;
int mp = 0;
int cnt = 0;

void dfs(int x, int len, int num);

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d %d %d", &N, &M, &S, &D);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &P[i]);
	}
	int c1, c2, len;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &c1, &c2, &len);
		G[c1][c2] = G[c2][c1] = len;
	}

	vis[S] = 1;
	dfs(S, 0, P[S]);
	printf("%d %d\n", cnt, mp);

	return 0;
}

void dfs(int x, int len, int num)
{
	//vis[x] = 1;
	if (len > mlen)
		return;

	if (x == D)
	{
		if (len < mlen)
		{
			cnt = 1;
			mlen = len;
			mp = num;
		}
		else if (len == mlen)
		{
			mp = max(num, mp);
			cnt++;
		}
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (G[x][i] > 0 && vis[i] == 0)
		{
			vis[i] = 1;
			dfs(i, len + G[x][i], num + P[i]);
			vis[i] = 0;
		}
	}
	//vis[x] = 0;
	return;
}

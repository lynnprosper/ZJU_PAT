#include <iostream>
#include <vector>
using namespace std;

int C, N, D, M, hc;
vector<int> rv, tv;
int mlen = 0x7ffffff;
int mtake, mbring;
int tlen;
const int Max = 6;
int G[Max][Max] = { 0 };
int vis[Max] = { 0 };
int bk[Max] = { 0 };

void dfs(int x, int len, int bring, int take);

int main()
{
	freopen("in.txt", "r", stdin);
	scanf("%d %d %d %d", &C, &N, &D, &M);
	hc = C / 2;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &bk[i]);
	}
	for (int i = 0; i < M; i++)
	{
		int s, d, wt;
		scanf("%d %d %d", &s, &d, &wt);
		G[s][d] = G[d][s] = wt;
	}

	vis[0] = 1;
	dfs(0, 0, 0, 0);
	printf("%d 0", mbring);
	for (int i = 0; i < rv.size(); i++)
	{
		printf("->%d", rv[i]);
	}
	printf(" %d\n", mtake);

	return 0;
}

void dfs(int x, int len, int bring, int take)
{
	if (len > mlen)
		return;
	if (x == D)
	{
		if (len < mlen)
		{
			mlen = len;
			mbring = bring;
			mtake = take;
			rv = tv;
		}
		else if (len == mlen)
		{
			if (bring < mbring)
			{
				mbring = bring;
				mtake = take;
				rv = tv;
			}
			else if (bring == mbring)
			{
				if (take < mtake)
				{
					mtake = take;
					rv = tv;
				}
			}
		}

		return;
	}	

	for (int w = 1; w <= N; w++)
	{
		if (vis[w] == 0 && G[x][w] > 0)
		{
			vis[w] = 1;
			tv.push_back(w);

			int ntake = take, nbring = bring;
			if (bk[w] > hc)
			{
				ntake = (bk[w] - hc + take);

			}
			else
			{
				if (bk[w] + take > hc)
				{
					ntake = bk[w] + take - hc;
				}
				else
				{
					nbring = (nbring + hc - bk[w] - take);
					ntake = 0;
				}
			}

			dfs(w, len + G[x][w], nbring, ntake);
			vis[w] = 0; 
			tv.pop_back();
		}
	}

	return;
}

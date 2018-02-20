#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K, P, msum = 0;
vector<int> re, tmp;

void dfs(int x, int d);
int get_sum();
/*
用STL重写了一遍。
已AC.
*/

int main()
{
	freopen("in.txt", "r", stdin);
	scanf("%d %d %d", &N, &K, &P);
	dfs(N, 100);
	if (re.size() != K)
		printf("Impossible\n");
	else
	{
		printf("%d = ", N);
		for (int i = 0; i < K; i++)
		{
			if (i != 0)
				printf(" + ");
			printf("%d^%d", re[i], P);
		}
		printf("\n");
	}

	return 0;
}

void dfs(int x, int d)
{
	if (x < 0 || tmp.size() > K)
		return;
	if (x == 0)
	{
		if (tmp.size() == K)
		{
			int sum = get_sum();
			if (sum > msum)
			{
				re = tmp;
				msum = sum;
			}
		}
		return;
	}

	int lt = sqrt(double(x));
	for (int i = min(lt, d); i > 0; i--)
	{
		tmp.push_back(i);
		dfs(x - (int)pow(i, P), i);
		tmp.pop_back();
	}
	return;
}

int get_sum()
{
	int re = 0;
	for (int i = 0; i < tmp.size(); i++)
	{
		re += tmp[i];
	}
	return re;
}

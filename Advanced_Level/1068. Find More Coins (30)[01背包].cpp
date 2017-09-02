#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

const int MN = 10005;
const int MM = 105;
int dp[MM] = { 0 };
int cho[MN][MM] = { 0 };
int flag[MN] = { 0 };
int w[MN] = { 0 };

int main()
{
	//freopen("in.txt", "r", stdin);
	int M, N;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &w[i]);
	}

	sort(w + 1, w + N + 1, greater<int>());

	for (int i = 1; i <= N; i++)
	{
		for (int v = M; v >= w[i]; v--)
		{
			if (dp[v] <= dp[v - w[i]] + w[i])
			{
				dp[v] = dp[v - w[i]] + w[i];
				cho[i][v] = 1;
			}
			else
				cho[i][v] = 0;
		}
	}

	if (dp[M] != M)
	{
		printf("No Solution\n");
	}
	else
	{
		int v = M;
		vector<int> re;
		for (int i = N; i > 0 && v >= 0; i--)
		{
			if (cho[i][v] == 1)
			{
				re.push_back(w[i]);
				v -= w[i];
			}
		}

		for (int i = 0; i < re.size(); i++)
		{
			if (i != 0)
			{
				printf(" ");
			}
			printf("%d", re[i]);
		}
		printf("\n");
	}

	return 0;
}

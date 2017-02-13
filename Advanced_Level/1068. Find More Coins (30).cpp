#include<iostream>
#include<algorithm>//使用sort函数
#include<vector>
#include<functional>//使用仿函数greater，用于降序排序
using namespace std;

const int MaxN = int(1e4 + 5);//最大硬币数目
const int MaxM = 100 + 5;//最大金额
int flag[MaxN][MaxM] = { 0 };//标记某个面值是否选择
int dp[MaxN][MaxM] = { 0 };//动态规划的主体数组，初始化为0
int value[MaxN] = { 0 };//给定的硬币数

/*
题意：
根据给定金额，从硬币中选出最小的硬币组合。
思路：
01背包问题。当然可以用bfs+剪枝，不过没有dp简捷些。
01背包不熟悉的，可以参考这里： <http://blog.csdn.net/mu399/article/details/7722810> 
状态转移方程：dp[i][j] = max(dp[i-1][j], dp[i-1][j - v[i]] + v[i]);
第一维表示有i个硬币，第二维是组合出的金额。值表示从中可以组合出的不超过j的最大金额。
枚举完，若dp[n][m] = m, 说明有解。
那如何输出路径呢？
我们还需要一个标记数组，f[i][j] = 1, 表示金额为j时硬币v[i]被选取了。
最后的时候，通过逆序从小到大回溯输出被选取的硬币就好了。所以在dp之前，要把硬币降序排序，
才能回溯输出最小组合。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> value[i];
	sort(value + 1, value + N + 1, greater<int>());//降序，为了后面的回溯

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (j < value[i] || (dp[i - 1][j - value[i]] + value[i]) < dp[i - 1][j])
				dp[i][j] = dp[i - 1][j];//第一个条件是当前币值已大于金额，第二个条件i-1个硬币时金额已最大
			else
			{
				dp[i][j] = dp[i - 1][j - value[i]] + value[i];//状态转移
				flag[i][j] = 1;//选择value[i]
			}
		}
	}

	if (dp[N][M] != M)
		cout << "No Solution\n";
	else
	{
		vector<int> path;
		int n = N, m = M;
		while (m > 0)
		{
			while(flag[n][m] == 0)//从小币值到达币值回溯
				n--;
			path.push_back(value[n]);
			m -= value[n];
			n--;
		}

		for (int i = 0; i < path.size(); i++)
		{
			if (i == 0)
				cout << path[i];
			else
				cout << ' ' << path[i];
		}
		cout << endl;
	}

	return 0;
}

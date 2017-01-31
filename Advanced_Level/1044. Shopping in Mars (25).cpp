#include<iostream>
#include<map>
#include<vector>
using namespace std;
const int INF = 0x7FFFFFFF;//表示无穷大

/*
题意：
问题抽象出来就是给定一串数字，找出所有子串数字和=给定值M的序列。
如果没有，就找出比M大但最小的所有子串数字和序列。
思路：
逻辑处理题。有点类似于动态规划。
既然是两种情况，先是一次循环，找出相等的，同时记录大于M的最小值X。
若没有相等的，执行第二次循环，找出等于X的序列首末端。
这里存储首末，我用的map映射，也可以用两个数组。
注意：不要用cin，会超时。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> sev(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &sev[i]);

	int mingre = INF;//存储比M大的最小值
	map<int, int> eqmp, mgmp;//分别存储相等和大于两种情况的序列首末端。
	for (int i = 0; i < N; i++)
	{
		int sum = 0;//子串和
		int sta, end;//首末编号
		sta = end = i;
		for (int j = i; j < N; j++)
		{
			sum += sev[j];
			end = j;
			if (sum == M)
			{
				eqmp[sta] = end;
				if (j == N - 1)
					goto output;//这里进行了优化，到了尾端跳出
				else
					break;
			}

			if (mingre == INF && sum > M)//更新比M大的最小值
			{
				mingre = sum;
				break;
			}
			else if (mingre != INF && sum > M)
			{
				mingre = sum < mingre ? sum : mingre;
				break;
			}
		}
	}

	if (eqmp.empty())//第二种情况
	{
		for (int i = 0; i < N; i++)
		{
			int sum = 0;
			int sta, end;
			sta = end = i;
			for (int j = i; j < N; j++)
			{
				sum += sev[j];
				end = j;
				if (sum == mingre)
				{
					mgmp[sta] = end;
					if (j == N - 1)
						goto output;
					else
						break;
				}
			}
		}
	}

	output: map<int, int>::iterator it;//输出
	if (!eqmp.empty())
	{
		for (it = eqmp.begin(); it != eqmp.end(); it++)
			printf("%d-%d\n", it->first + 1, it->second + 1);
	}
	else
	{
		for (it = mgmp.begin(); it != mgmp.end(); it++)
			printf("%d-%d\n", it->first + 1, it->second + 1);
	}

	return 0;
}

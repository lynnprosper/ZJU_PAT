#include<iostream>
#include<algorithm>//使用min，max函数
#include<vector>
using namespace std;

/*
题意：
在一个环路中，求两点间的最小距离。基本逻辑题。
思路：
常规思路是求出总长total，然后累计两点间的正向距离sum。
反向距离是total-sum，输出两者的最小值。
然而数组规模很大，最后一个测试点超时。
改进的思路参考自：http://blog.csdn.net/xyt8023y/article/details/46924653
即：另开一个数组，在求total时，保存从起点1到当前点的距离。
这样就少了一层循环。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N, total = 0;
	scanf("%d", &N);
	vector<int> ev(N + 1, 0);//保存两点间的距离
	vector<int> acc(N + 1, 0);//保存起点到当前点的距离
	for (int i = 1; i <= N; i++)
	{
		acc[i] = total;
		scanf("%d", &ev[i]);
		total += ev[i];
	}

	int M, sta, end;//分别为所求问题个数， 起始点，末点。
	int lnum, gnum;//分别表示两点较小的和较大的序号
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &sta, &end);
		lnum = min(sta, end);
		gnum = max(sta, end);

		int sum = acc[gnum] - acc[lnum];
		int min_dist = sum > (total / 2) ? (total-sum) : sum;
		printf("%d\n", min_dist);
	}

	return 0;
}

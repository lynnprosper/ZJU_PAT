#include<iostream>
#include<vector>
#include<set>
using namespace std;

/*
题意：
判断两个数列中的相同元素个数与所有不同元素的比例。
思路：
数学逻辑题。首先要对读入的数列去重，这样我们想到了用stl中的set或者map。
最终两个set中的元素都是不同的，然后遍历其中一个，查看是否在另一个set中存在，
记录相同元素个数。最后输出就好了。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	vector< set<int> > sev(N+1);//从1~N的集合，跳过0，方便后续操作。
	
	for (int i = 1; i <= N; i++)
	{
		int m, tem;
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &tem);
			sev[i].insert(tem);//插入set，若存在，会忽略的，这样就去重了。
		}
	}

	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int id1, id2;
		scanf("%d %d", &id1, &id2);

		set<int>::const_iterator it;
		int common = 0;
		int tot = sev[id1].size() + sev[id2].size();
		for (it = sev[id1].begin(); it != sev[id1].end(); it++)//遍历统计相同元素。
		{
			if (sev[id2].count(*it) > 0)
				common++;
		}
		printf("%.1f%%\n", 100 * double(common) / (tot - common));
	}

	return 0;
}

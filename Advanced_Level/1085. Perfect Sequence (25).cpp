#include<iostream>
#include<algorithm>//使用sort函数
#include<vector>
using namespace std;
typedef long long int lint;

/*
题意：
给定一个序列，找出序列中两个元素m和M之间的满足M<= m*p关系的元素个数最大值。
思路：
排序逻辑题。
先升序排序，然后利用动态规划的思想遍历即可。
即，假设起点第i个位置，i~j之间都满足，j+1不符合。
那么求出此时元素个数，i++继续循环处理。
注意用long long int.
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	lint N, p;
	cin >> N >> p;
	vector<lint> seq(N);//存储元素
	for (int i = 0; i < N; i++)
		cin >> seq[i];
	sort(seq.begin(), seq.end());//升序

	int m = 0, num;//分别为起始位置， 元素个数
	int M = 0, cnt = 0;//分别为终点位置， 最大个数
	while (m < N)//循环
	{
		lint range = seq[m] * p;//满足条件的元素最大值
		while (M < N && seq[M] <= range)
			M++;

		num = M - m;
		cnt = max(cnt, num);//更新最大个数
		if (M == N)//已到序列末尾，跳出
			break;
		else
			m++;
	}

	cout << cnt << endl;

	return 0;
}

#include <iostream>
using namespace std;

/*
题意：数学逻辑题。求所有连续子序列元素之和。
思路：
这题要找规律，即找出某个元素在所有子序列中出现的次数。
不妨设a为第i个元素（从1开始），那么a前面有i-1元素，根据连续子序列的
构成方法，那么包含a的子序列有i个。然后再看后面，有N-i个元素。
则a和后面的可以构成N-i+1个已a开头的连续子序列。
根据组合方式，共有i*（N-i+1)个含有a的连续子序列。
所有总次数即为i*（N-i+1)。
剩下就累加好了。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N;
	double sum = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		double tmp;
		scanf("%lf", &tmp);
		sum += tmp * i * (N - i + 1);//进行累加
	}
	printf("%.2f\n", sum);

	return 0;
}

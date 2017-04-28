#include <iostream>
#include <algorithm>//使用sqrt函数
using namespace std;

/*
题意：找出一个数的最大连续的因子数。数学逻辑题
注意，因子不一定是素数，只要连续即可。
思路：
最容易想到的方法就是穷举法了。可以优化的是因子的最大值。
因子最大值不会超过数的开方，然后遍历即可。
已AC。
*/
int main(void)
{
	int N;
	int maxCount = 0;//最大个数
	int firstFactor;//结果的第一个起始因子
	cin >> N;

	int nlimit = sqrt((double)N);
	for (int i = 2; i <= nlimit; i++)//遍历
	{
		int tem = N;
		int start = i;
		while (tem % start == 0)
		{
			tem /= start;
			start++;
		}

		if (start - i > maxCount)//更新最大值
		{
			maxCount = start - i;
			firstFactor = i;
		}
	}

	if (maxCount == 0)//说明是素数，输出它本身
	{
		cout << "1\n" << N << endl;
	}
	else
	{
		cout << maxCount << endl;
		for (int i = 0; i < maxCount; i++)
		{
			if (i != 0)
				cout << '*';
			cout << firstFactor++;
		}
		cout << endl;
	}

	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>//使用仿函数greater<int>()
using namespace std;

/*
题意：基础逻辑题。
在一组数中，找出m个数都大于m的。
思路：
数字按照降序排序，设置一个变量cnt，然后开始遍历比较即可。
已AC。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());//降序

	int cnt = 1;//初始1，不能是0.因为第一天是有一天是大于1的。
	for (int i = 0; i < N; i++)
	{
		if (v[i] > cnt)
			cnt++;
		else
		{
			break;
		}
	}
	cout << --cnt << endl;//此时的cnt是多了1，要减去

	return 0;
}

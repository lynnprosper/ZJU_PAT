#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
题意：基本逻辑题。
给出一组整数，划分成两部分，使得个数之差最小且和的差最大。
思路：
显然，直接顺序排序，然后均分成两组，统计和就行了。
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
	sort(v.begin(), v.end());//升序排序
	
	int sum1, sum2;
	sum1 = sum2 = 0;
	for (int i = 0; i < N / 2; i++)
	{
		sum1 += v[i];
	}
	for (int i = N / 2; i < N; i++)
	{
		sum2 += v[i];
	}

	int difference = (N % 2 == 0 ? 0 : 1);//个数差不是0就是1.
	cout << difference << ' ' << sum2 - sum1 << endl;

	return 0;
}

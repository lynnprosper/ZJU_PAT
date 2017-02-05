#include<iostream>
#include<map>
using namespace std;

/*
题意：
给出一系列面值及应付的钱，取出两个面值付款。存在多个，输出第一个最小的。
思路：
数据处理，比较简单。可以用数组。
习惯用stl了，我用的map映射。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	map<int, int> monp;//key是面值，value是张数。
	for (int i = 0; i < N; i++)//读入数据
	{
		int val;
		cin >> val;
		if (monp.count(val) == 0)
			monp[val] = 0;
		monp[val]++;
	}

	map<int, int>::iterator it;
	for (it = monp.begin(); it != monp.end() && it->first <= M/2; it++)//处理到小于等于M的一半就行
	{
		int sub_val = M - it->first;
		if (sub_val == it->first && it->second > 1)//相同面值有多张
		{
			cout << sub_val << ' ' << sub_val << endl;
			return 0;
		}

		if (sub_val != it->first && monp.count(sub_val) == 1)//不同面值
		{
			cout << it->first << ' ' << sub_val << endl;
			return 0;
		}
	}
	cout << "No Solution\n";

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
题意：数学逻辑题。
给出一组绳子的长度。两段拼接后的长度为总长的一半。求出可以拼接的最大长度。
思路：
因为每次拼接，原来的长度都变为一半。
显然只有从最短的逐渐拼接才能最长。
剩下的就简单了。
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

	double len = v[0];
	for (int i = 1; i < N; i++)//累计长度
	{
		len = (len + v[i]) / 2;
	}
	cout << (int)len << endl;//输出整数长度

	return 0;
}

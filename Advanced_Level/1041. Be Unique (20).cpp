#include<iostream>
#include<map>
#include<vector>
using namespace std;

/*
题意：
给出N个数字，求出只出现一次的第一个数字。
思路：
基础的逻辑题，比较简单。
用map，存储出现次数，同时把数字压入vector。
然后遍历vector，输出第一个出现一次的数字。
*/
int main(void)
{
	freopen("in.txt", "r", stdin);
	int N;
	cin >> N;
	vector<int> nv(N);
	map<int, int> nmp;

	for (int i = 0; i < N; i++)//读入数据
	{
		cin >> nv[i];
		if (nmp.count(nv[i]) == 0)
			nmp[nv[i]] = 0;
		nmp[nv[i]]++;
	}

	for (int i = 0; i < N; i++)//遍历vector
	{
		if (nmp[nv[i]] == 1)
		{
			cout << nv[i] << endl;
			return 0;
		}
	}
	cout << "None\n";

	return 0;
}

#include<iostream>
using namespace std;
const int M = 54;

/*
题意：按照给定交换规则排序。基础逻辑题
思路：比较简单，用两个数组a,b
a存储交换前的，b存储交换后的。
*/
int main(void)
{
	freopen("in.txt", "r", stdin);
	int a[M], b[M], ord[M];
	int n;
	char ch[5] = { 'S', 'H', 'C', 'D', 'J' };//为了便于输出
	cin >> n;
	for (int i = 0; i < M; i++)//初始化
		a[i] = i;

	for (int i = 0; i < M; i++)
	{
		int tem;
		cin >> tem;
		ord[i] = tem - 1;//为了便于处理，把题中的位置-1；
	}

	for (int i = 0; i < n; i++)//循环洗牌n次
	{
		for (int j = 0; j < M; j++)
			b[ord[j]] = a[j];
		for (int j = 0; j < M; j++)
			a[j] = b[j];
	}

	for (int i = 0; i < M; i++)//输出
	{
		if (i == 0)
			cout << ch[a[i] / 13] << a[i] % 13 + 1;
		else
			cout << ' ' << ch[a[i] / 13] << a[i] % 13 + 1;
	}

	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

//思路：逻辑题。从大到小排序，满足D[i]>i+1 的最大值即可。
int cmp(const int a, const int b);
int main()
{
	freopen("in.txt", "r", stdin);
	int N;
	cin >> N;
	int *D = new int[N];
	int i;
	for (i = 0; i < N; i++)
		cin >> D[i];

	sort(D, D + N, cmp);
	for (i = 0; i < N; i++)
	{
		if (D[i] <= i+1)
			break;
	}
	cout << i << endl;

	delete[] D;
	return 0;
}

int cmp(const int a, const int b)
{
	return a > b;
}

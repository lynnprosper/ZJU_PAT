#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a);//求数位和；
int main()
{
	//freopen("in.txt", "r", stdin);
	int a[50] = { 0 };//和不超过36，下标与数位和进行映射；
	int N, i, t, re, cnt = 0;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> t;
		re = gcd(t);
		if (a[re] == 0)
		{
			a[re] = 1;
			cnt++;
		}
	}
	cout << cnt << endl;

	int flag = 1;
	for (i = 0; i < 50; i++)
	{
		if (a[i] == 1)
		{
			if (flag)
			{
				cout << i;
				flag = 0;
			}
			else
				cout << ' ' << i;
		}
	}
	cout << endl;

	//system("pause");
	return 0;
}
int gcd(int a)
{
	int sum = 0;
	while (a > 0)
	{
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

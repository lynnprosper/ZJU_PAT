#include<iostream>
#include<algorithm>
using namespace std;

/*
思路：建两个Max大的数组，一个用来配对情侣，另一个记录到场人的id；
然后排序，遍历输出；
*/
#define Max 100001
int main()
{
	//freopen("in.txt", "r", stdin);
	int D[Max] = { 0 };//下标映射在场ID；
	int P[Max] = { 0 };//下标映射情侣ID；
	int N, M, i, t, a, b, cnt;
	cin >> N;

	for (i = 0; i < N; i++)
	{
		cin >> a >> b;//为了操作方便，排除0的影响，ID从1开始；
		a++;
		b++;
		P[a] = b;//互相映射；
		P[b] = a;
	}
	cin >> M;
	cnt = M;
	int *s = new int[M];
	for (i = 0; i < M; i++)
	{
		cin >> t;
		s[i] = ++t;
		D[t] = 1;//到场置为1；
	}

	for (i = 0; i < M; i++)
	{
		if (D[P[s[i]]] == 1)	//情侣都在，人数--；
		{
			s[i] = 0;
			cnt--;
		}
	}
	sort(s, s + M);
	cout << cnt << endl;

	int flag = 1;
	for (i = 0; i < M; i++)	//输出；
	{
		if (s[i] > 0)
		{
			if (flag)
			{
				printf("%05d", s[i]-1);
				flag = 0;
			}
			else
				printf(" %05d", s[i] - 1);
		}
	}

	//system("pause");
	return 0;
}

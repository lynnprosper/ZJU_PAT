#include<iostream>
using namespace std;

//读入数据，累加即可
int main()
{
	int N, M, i, j;
	cin >> N >> M;
	int *a = new int[M];
	int *b = new int[M];

	for (i = 0; i < M; i++)
		cin >> a[i];
	for (i = 0; i < M; i++)
		cin >> b[i];

	int t, sum;
	for (j = 0; j < N; j++)
	{
		sum = 0;
		for (i = 0; i < M; i++)
		{
			cin >> t;
			if (t == b[i])	//判断正确，累加；
				sum += a[i];
		}
		cout << sum << endl;
	}

	//system("pause");
	return 0;
}

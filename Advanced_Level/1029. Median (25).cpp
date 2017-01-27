#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int lint;

/*
题意：
比较简单，就是求两个有序序列合并后的中位数。
思路：有多种方法。
可以用队列，也可以数下标。
由于数据较多，不知直接用sort是否可行。
此处采用数下标，数到中间的输出即可。
注：有两个1分的测试点未过，欢迎指正。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int N, M;
	scanf("%d", &N);
	vector<lint> a(N);
	for(int i = 0; i < N; i++)//读入数据
		scanf("%d", &a[i]);
	
	scanf("%d", &M);
	vector<lint> b(M);
	for(int i = 0; i < M; i++)
		scanf("%d", &b[i]);

	int middle = (N+M-1)/2 + 1;	//中位数的位置，从1开始
	int i;
	int j = 0, k = 0;
	lint mid;	//存储中位数
	for (i = 0; i < middle && j < N && k < M; i++)	//数下标
	{
		if (a[j] <= b[k])
		{
			mid = a[j];
			j++;
		}
		else
		{
			mid = b[k];
			k++;
		}
	}
	while(i < middle)	//表明某个序列输完了
	{
		if(j == N)
		{
			mid = b[k];
			k++;
		}
		else
		{
			mid = a[j];
			j++;
		}
		i++;
	}

	cout << mid << endl;

	return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
题意：
给出的信息很复杂，其实就是求两个集合中的数相乘后的和的最大值。
条件是每个数只能用1一次。
思路：
如何让和最大，显然乘积必须大于0.
于是我们就有了思路，排序后，两个最大的正数相乘或者两个最小的负数相乘。
实现就用vector，也可以用动态数组。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int nc, np;
	cin >> nc;
	vector<int> cou(nc);//奖券vector
	for (int i = 0; i < nc; i++)
		cin >> cou[i];
	cin >> np;
	vector<int> pro(np);//产品vector
	for (int i = 0; i < np; i++)
		cin >> pro[i];

	sort(cou.begin(), cou.end(), greater<int>());//降序
	sort(pro.begin(), pro.end(), greater<int>());
	int sum = 0, i, j;
	for (i = 0, j = 0; i < nc && j < np; i, j)//正数相乘的情况，从0开始
	{
		if ( cou[i] > 0 && pro[j] > 0)
			sum += cou[i++] * pro[j++];
		else
			break;
	}

	for ( i = nc-1, j = np-1; i >= 0, j >= 0; i,j)//负数相乘，从尾端开始
	{
		if(cou[i] < 0 && pro[j] < 0)
			sum += cou[i--] * pro[j--];
		else
			break;
	}
	cout << sum << endl;

	return 0;
}

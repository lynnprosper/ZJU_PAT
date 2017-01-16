#include<iostream>
using namespace std;

/*
思路：题意是求最大连续子列和。有多种方法，可以用brute force，分而治之法，
最简单的是动态规划法。
即假设a[i]之前的连续和now_sum，要使加上a[i]后和更大，必须now_sum > 0。
遍历每个元素后，用now_sum和max_sum比较，若now_sum > max_sum, 则更新max_sum, 同时
更新第一个元素first和最后一个元素last.
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int k, i;
	cin >>k;
	int *a = new int[k];
	for(i = 0; i < k; i++)
		cin >> a[i];
	int max_sum, now_sum, first, last;
	int now_first, now_last;
	now_sum = first = last = max_sum = a[0];
	now_first = now_last = a[0];
	for( i = 1; i < k; i++)
	{
		if(now_sum > 0)	//注意此处不能取等号，因题意要求最小的下标，下同。
		{
			now_sum += a[i];
			now_last = a[i];
		}
		else
		{
			now_first = now_last = a[i];
			now_sum = a[i];
		}

		if(now_sum > max_sum)	//不能取等号
		{
			first = now_first;
			last = now_last;
			max_sum = now_sum;
		}

	}
	if(max_sum < 0)	//表示元素全为负值
		cout << 0 << " " << a[0]
		<< " " << a[k-1] <<endl;
	else
		cout << max_sum << " " << first
		<< " " << last <<endl;

	delete[] a;
	return 0;
}

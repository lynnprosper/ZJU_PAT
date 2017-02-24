#include<iostream>
#include<vector>
#include<algorithm>//使用sort排序函数，pow指数函数
#include<functional>//使用内置降序比较greater仿函数
using namespace std;

int x, N, p;//分别为给定的正数， 因子个数及指数
int maxsum = -1, cur_sum = 0;//分别为因子和的最大值，当前因子和
vector<int> factor, result;//分别为因子和最终所求的因子的数组容器
void dfs(int x, int cnt);//递归遍历
void print();//输出结果

/*
题意：
判断一个数能否分解成N个因子的p次方的和。
若是，求出最大的N个因子和。
有多个相同最大和，输出较大的那个序列。比如 1) 1, 2, 3, 5
2） 1, 2, 4, 4
则输出第二种。
递归剪枝题。

思路：
题意并不算多难，但是如何转换成合适的算法呢。
首先会想到暴力破解的方式，毕竟x<=400, 那么因子最大是20.
所以不妨从1~20一个个试得了。这样的思路是对的。
我们可以优化。毕竟是N个因子，超出N个的话就不需要继续判断了。
遍历的过程中，我们从最小值1开始测试，同时记录因子和，若遇到更大的或者相等的，都更新。
这样也满足题目中的多个相同和的情况。

思路整理下，就是递归+剪枝优化的算法。
即当前元素值x，把因子i作为它的一个，那么新的x = x - i^p， 把因子i加入容器factor中.
接着对新的x递归遍历，这时的遍历因子从i开始，而不是从1开始了（因为前面的已经递归处理了）。
递归完成后输出结果就好了。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	cin >> x >> N >> p;
	factor.resize(N);
	dfs(x, 0);//递归遍历因子，参数为元素值，因子的下标顺序。N个因子，下标从0~N-1

	if (maxsum == -1)//说明未找到
		cout << "Impossible\n";
	else
		print();

	return 0;
}

void dfs(int x, int cnt)//递归遍历因子，参数为元素值，因子的下标顺序。N个因子，下标从0~N-1
{
	if (cnt == N && x != 0)//剪枝优化，已经有N个因子，但和不等于给定的值
		return;
	if (x < 0)//剪枝优化，超出了给定值。直接返回
		return;

	if (x == 0 && cnt == N)//可分解成N个因子，更新
	{
		cur_sum = 0;//因子和
		for (int i = 0; i < N; i++)
			cur_sum += factor[i];

		if (cur_sum >= maxsum)//更新最大和，相等也更新，这样才满足最大的因子序列
		{
			maxsum = cur_sum;
			result = factor;//因子赋值给结果容器
		}
		return;
	}

	int start = cnt > 0 ? factor[cnt - 1] : 1;//因子起点，第一个因子递归时，因子值从1开始。否则是上一个因子值
	int end = (int)sqrt(double(x));//因子终点
	for (int fac = start; fac <= end; fac++)//因子值从小到大进行递归遍历
	{
		factor[cnt] = fac;//把新的因子压入容器
		dfs(x - (int)pow(fac, p), cnt + 1);
	}

	return;
}

void print()//输出
{
	sort(result.begin(), result.end(), greater<int>());
	printf("%d = ", x);

	for (int i = 0; i < result.size(); i++)
	{
		if (i != 0)
			printf(" + ");
		printf("%d^%d", result[i], p);
	}
	printf("\n");
}

#include<iostream>
#include<algorithm>//使用sqrt函数
#include<vector>
using namespace std;

int N, len;//分别为元素个数， 给定的散列表长度
vector<int> flag;//标记是否有元素
int isPrime(int x);//是否素数
int getSize(int x);//求出散列表长度
int hashKey(int x);//求散列地址

/*
题意：求散列地址，冲突解决方法是平方探测法。
思路：
不熟悉散列表的翻下书哈。
题目要求表长是大于等于给出长度的素数。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &len, &N);
	len = getSize(len);//求出表长度
	flag.resize(len, 0);

	int key, pos;//分别为元素值， 散列地址
	for (int i = 0; i < N; i++)
	{
		if (i != 0)
			printf(" ");

		scanf("%d", &key);
		pos = hashKey(key);
		if (pos == -1)//无法散列
			printf("-");
		else
			printf("%d", pos);
	}
	printf("\n");

	return 0;
}

int isPrime(int x)//是否素数
{
	if (x == 1)
		return 0;
	for (int i = 2; i <= (int)sqrt(x); i++)
	{
		if (x % i == 0)
			return 0;
	}

	return 1;
}

int getSize(int x)//求出散列表长度
{
	if (isPrime(x) == 1)
		return x;

	int i;
	for (i = x + 1; i; i++)
	{
		if (isPrime(i) == 1)
			break;
	}
	return i;
}

int hashKey(int x)//求散列地址
{
	int val = x % len;//散列地址
	if (flag[val] == 0)//表示该地址为空
	{
		flag[val] = 1;
		return val;
	}

	int cnt = 0;//记录冲突次数
	int k = 0;
	while (k <= len / 2)//平方探测法的最大增量
	{
		cnt++;
		if (cnt % 2 == 1)//奇数次冲突
		{
			k++;
			val = (val + k*k) % len;
		}
		else//偶数次冲突
		{
			val -= k*k;
			while (val < 0)//使得val符合正常范围
				val += len;
		}

		if (flag[val] == 0)
		{
			flag[val] = 1;
			return val;
		}
	}

	return -1;//无法散列
}

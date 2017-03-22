#include<iostream>
typedef long long int lint;//使用长整型
using namespace std;

lint gcd(lint a, lint b);//求最大公约数

/*
题意：
其实就是输出最简分数。
思路：
两个两个相加，最后再化简。
要点：
1.结果是整数，只输出整数；
2.若是负数， 整数和分数的分子都有负号；
3.结果可能为0；
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	lint a = 0;
	lint b = 0;
	lint n;
	scanf("%lld", &n);
	scanf("%lld/%lld", &a, &b);//先读一组数据

	for (int i = 1; i < n; i++)//从1开始循环
	{
		lint c, d;
		scanf("%lld/%lld", &c, &d);
		a = a*d + b*c;//加法处理
		b = b*d;
	}

	if (a == 0)//结果0的特殊情况
	{
		printf("0\n");
		return 0;
	}
	lint intPart = a / b;//整数部分
	if (intPart != 0)
		printf("%lld", intPart);

	a %= b;
	if (a == 0)//只有整数情况
		return 0;
	if (intPart != 0)
		printf(" ");
	if (a < 0)//先输出负号
	{
		printf("-");
		a = -a;
	}

	lint factor = gcd(a, b);//求最大公约数
	a /= factor;
	b /= factor;
	printf("%lld/%lld\n", a, b);//输出分数部分

	return 0;
}

lint gcd(lint a, lint b)//辗转相除法求最大公约数
{
	return (a == 0 ? b : gcd(b%a, a));
}

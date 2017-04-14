#include <iostream>
#include <algorithm>
using namespace std;

typedef long long lint;
lint a, b, c, d;

lint gcd(lint a, lint b);//取得两数的最大公约数
void reduced(lint a, lint b);//化为最简
void add(void);//加法
void difference(void);//减法
void product(void);//乘法
void Quotient(void);//除法

/*
题意：既定格式的四则运算。基本逻辑题。
思路：
题意不难，但是要分情况，考察细节。
要点：整数要用长整型，分情况讨论就好了。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	add();
	difference();
	product();
	Quotient();

	return 0;
}

lint gcd(lint a, lint b)//辗转相除求公约数
{
	return a == 0 ? b : gcd(b%a, a);
}

void reduced(lint a, lint b)
{
	if (b == 0)//以下分情况化简
	{
		printf("Inf");
		return;
	}

	if (a == 0)
	{
		printf("0");
		return;
	}

	if (a < 0)
	{
		printf("(-");
		a = -a;

		lint common = gcd(a, b);
		a /= common;
		b /= common;
		
		if (a < b)
			printf("%lld/%lld)", a, b);
		else if (a == b)
			printf("1)");
		else
		{
			if (a%b != 0)
				printf("%lld %lld/%lld)", a / b, a%b, b);
			else
				printf("%lld)", a / b);
		}
	}
	else
	{
		lint common = gcd(a, b);
		a /= common;
		b /= common;

		if (a < b)
			printf("%lld/%lld", a, b);
		else if (a == b)
			printf("1");
		else
		{
			if (a%b != 0)
				printf("%lld %lld/%lld", a / b, a%b, b);
			else
				printf("%lld", a / b);
		}
	}
}

void add(void)
{
	reduced(a, b);
	printf(" + ");
	reduced(c, d);
	printf(" = ");

	lint e, f;
	e = a * d + b * c;
	f = b * d;
	reduced(e, f);
	printf("\n");

	return;
}
void difference(void)
{
	reduced(a, b);
	printf(" - ");
	reduced(c, d);
	printf(" = ");

	lint e, f;
	e = a * d - b * c;
	f = b * d;
	reduced(e, f);
	printf("\n");

	return;
}
void product(void)
{
	reduced(a, b);
	printf(" * ");
	reduced(c, d);
	printf(" = ");

	lint e, f;
	e = a * c;
	f = b * d;
	reduced(e, f);
	printf("\n");

	return;
}
void Quotient(void)
{
	reduced(a, b);
	printf(" / ");
	reduced(c, d);
	printf(" = ");
	if (c * d < 0)//保证分母为正。
	{
		c = -c;
		d = -d;
	}

	lint e, f;
	e = a * d;
	f = b * c;
	

	reduced(e, f);
	printf("\n");

	return;
}

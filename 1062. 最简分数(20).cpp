#include<iostream>
using namespace std;

//第二个未通过；
int gcd(int a, int b);//求两个数的公约数；
int main()
{
	//freopen("in.txt", "r", stdin);
	int a, b, c, d, k;
	scanf("%d/%d %d/%d %d", &b, &a, &d, &c, &k);

	int i, m, flag = 1;
	m = (k*d%c == 0) ? (k*d / c - 1) : (k*d / c);//判断循环的最大边界；
	for (i = 1; i <= m; i++)	//从1开始，是最简输出；
	{
		if ((i*a - b*k >0) && (i*c - d*k < 0))	//在区间内（开区间）；
		{
			if (gcd(i, k) == 1)	//公约数为1最简；
			{
				if (flag)
				{
					printf("%d/%d", i, k);
					flag = 0;
				}
				else
					printf(" %d/%d", i, k);
			}
		}
	}
	printf("\n");

	//getchar();
	return 0;
}

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	else
		return gcd(b%a, a);
}

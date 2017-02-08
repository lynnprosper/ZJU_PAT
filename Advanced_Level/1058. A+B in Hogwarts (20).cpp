#include<iostream>
using namespace std;

/*
题意：
模拟十进制的加法进位运算。
思路：
比较简单，直接计算就好。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int g1, s1, k1;
	int g2, s2, k2;
	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);

	int g3, s3, k3;
	k3 = (k2 + k1) % 29;
	s3 = (s2 + s1 + (k2 + k1) / 29) % 17;
	g3 = g1 + g2 + (s2 + s1 + (k2 + k1) / 29) / 17;
	printf("%d.%d.%d\n", g3, s3, k3);

	return 0;
}

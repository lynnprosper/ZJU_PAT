#include<iostream>
using namespace std;

//基本的数据操作
int main()
{
	//freopen("in.txt", "r", stdin);
	int a, b, x;
	cin >> a >> b;
	x = a + b;
	if(x < 0)
	{
		printf("-");
		x = -x;
	}
	if(x > 999999)	//已经给定范围，分三种情况。
		printf("%d,%03d,%03d\n", x/1000000, x/1000%1000, x%1000);
	else if(x > 999)
		printf("%d,%03d\n", x/1000, x%1000);
	else
		printf("%d\n", x);

	return 0;
}
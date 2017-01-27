#include<iostream>
using namespace std;

char base[13] = {'0', '1', '2', '3', '4', '5',
	'6', '7', '8', '9', 'A', 'B', 'C'};
void Convert(int x, char *y);	//函数，转换成13进制

/*
题意：
10进制转成13进制.
比较简单，直接转换就好。
*/
int main()
{
	freopen("in.txt", "r", stdin);
	int r, g, b;
	cin >> r >> g >> b;

	char r2[3], g2[3], b2[3];
	Convert(r, r2);
	Convert(g, g2);
	Convert(b, b2);
	cout <<"#" << r2 << g2 << b2 << endl;

	return 0;
}

void Convert(int x, char *y)
{
	y[0] = base[x/13];
	y[1] = base[x%13];
	y[2] = '\0';	//注意字符串结束要加结束符
}

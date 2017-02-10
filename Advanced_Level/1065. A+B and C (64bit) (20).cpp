#include<iostream>
using namespace std;

typedef long long int lint;

/*
题意：
判断数的大小。
思路：
看到题目的时候，准备用字符串处理了。感觉有点麻烦，看了下其他网友的思路。
原来题目是没有考虑最大边界的。那就简单了。
64位的长整型范围是-2^63~2^63-1，如果考虑最大边界，只有用字符串判断了。

主要是上溢和下溢问题（同号相加才会出现溢出）。a>0, b > 0, 若a+b<0, 说明上溢了。
a<0, b<0, 若a+b>0, 说明下溢了。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N;
	cin >> N;
	lint a, b, c;
	for (int i = 0; i < N; i++)
	{
		cout << "Case #" << i + 1 << ": ";
		cin >> a >> b >> c;
		lint tem = a + b;
		int flag = 0;
		
		if (a > 0 && b > 0 && tem <= 0)//上溢
			flag = 1;
		else if (a < 0 && b < 0 && tem >= 0)//下溢
			flag = 0;
		else if (tem > c)
			flag = 1;
		
		if (flag == 1)
			cout << "true\n";
		else
			cout << "false\n";
	}
}

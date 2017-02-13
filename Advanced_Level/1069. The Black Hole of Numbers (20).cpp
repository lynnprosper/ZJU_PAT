#include<iostream>
#include<algorithm>//使用sort函数
#include<functional>使用仿函数greater，用来降序排序
using namespace std;

/*
思路：
主要是要把数字转换成字符串，进行排序，条件符合输出就好了。
我用的sprintf转换成字符串。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int num;
	cin >> num;
	int n1, n2, sub = num;
	char s[5];//存储字符串

	do//至少执行一次
	{
		int len = sprintf(s, "%d", sub);
		while (len < 4)//不够4位要补0
			s[len++] = '0';

		sort(s, s + 4, greater<char>());
		n1 = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + s[3] - '0';
		sort(s, s + 4);
		n2 = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + s[3] - '0';
		sub = n1 - n2;
		printf("%04d - %04d = %04d\n", n1, n2, sub);
	} while (sub != 0 && sub != 6174);//中断条件

	return 0;
}

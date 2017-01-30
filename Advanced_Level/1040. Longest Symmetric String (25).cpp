#include<iostream>
#include<string>
using namespace std;

/*
题意：
求最大的对称子串。文字处理题。
思路：
采用以每个字符为中心遍历的暴力方法。
需要注意奇偶对称两种情况。
*/
int main(void)
{
	freopen("in.txt", "r", stdin);
	string s;
	char ch;
	while ((ch = getchar()) != EOF)//字符可能不在一行
		s.push_back(ch);

	int maxlen = 0;
	int slen = s.size();
	for (int i = 0; i < slen; i++)
	{
		for (int j = 0; j <= i && j + i < slen; j++)//奇数序列
		{
			if (s[i - j] != s[i + j])
				break;				

			if ((j * 2 + 1) > maxlen)
				maxlen = j * 2 + 1;
		}

		for (int j = 0; j <= i && (j + i +1) < slen; j++)//偶数序列
		{
			if (s[i - j] != s[i + j +1])
				break;

			if ((j * 2+2) > maxlen)
				maxlen = j * 2 + 2;
		}
	}

	cout << maxlen << endl;

	return 0;
}

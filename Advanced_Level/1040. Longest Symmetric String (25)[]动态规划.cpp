#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	const int MAX = 1005;
	char s[MAX] = { 0 };
	gets(s);
	int len = strlen(s);
	int re = 0;
	int d[MAX][MAX] = { 0 };

	//先初始化长度1和2的子串
	for (int i = 0; i < len; i++)
	{
		d[i][i] = 1;
		re = 1;
		if (i < len - 1 && s[i] == s[i + 1])
		{
			d[i][i + 1] = 1;
			re = 2;
		}
	}

	//从长度3开始枚举
	for (int i = 3; i <= len; i++)
	{
		for (int j = 0; j + i - 1 < len; j++)
		{
			int right = j + i - 1;
			if (s[j] == s[right] && d[j + 1][right - 1] == 1)
			{
				d[j][right] = 1;
				re = i;
			}
		}
	}

	printf("%d\n", re);

	return 0;
}

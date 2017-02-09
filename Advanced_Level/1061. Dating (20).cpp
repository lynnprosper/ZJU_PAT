#include<iostream>
#include<string>
using namespace std;

/*
题意：
乙级福尔摩斯约会的英文版。查找相应字符转换成时间。
思路：
直接循环查找。注意日期的字符是在A~G,
小时的是0~9或者A~N；分钟的是A~Z或a~z的位置。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	char day[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;

	int d, h, m;
	int flag = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] >= 'A' && s1[i] <= 'G' && s1[i] == s2[i] && flag == 0)
		{
			d = s1[i] - 'A';//日期
			flag = 1;
			continue;
		}

		if (flag == 1 && s1[i] == s2[i])
		{
			if (s1[i] >= 'A' && s1[i] <= 'N')//小时
			{
				h = s1[i] - 'A' + 10;
				break;
			}
			else if (s1[i] >= '0' && s1[i] <= '9')
			{
				h = s1[i] - '0';
				break;
			}
		}
	}

	for (int i = 0; i < s3.size(); i++)//分钟
	{
		if (s3[i] == s4[i])
		{
			if ((s3[i] >= 'A' && s3[i] <= 'Z') || (s3[i] >= 'a' && s3[i] <= 'z'))
			{
				m = i;
				break;
			}
		}
	}

	printf("%s %02d:%02d\n", day[d], h, m);
	return 0;
}

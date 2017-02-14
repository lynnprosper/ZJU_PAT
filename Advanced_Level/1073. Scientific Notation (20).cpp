#include<iostream>
#include<vector>
using namespace std;
const int Max = 10010;//最大字符数目

/*
题意： 科学记数法的转换。
思路：
字符处理题。可以用string， 我用的char字符串。
然后分情况讨论就好了。
注意，“+”不输出。
已AC
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	char s[Max];
	cin.getline(s, Max);//读入一行字符串
	char sign = s[0];//±号标志
	vector<char> re;//存储结果，不包含小数点

	int i;
	for (i = 1; s[i] != 'E'; i++)
	{
		if (s[i] == '.')
			continue;
		re.push_back(s[i]);
	}
	int e_num;//指数
	i++;//自增后的位置就是指数的起点
	sscanf(s + i, "%d", &e_num);//字符串转换数字

	if (sign == '-')
		cout << sign;
	if (e_num < 0)//小数情况
	{
		for (int i = 0; i < -e_num; i++)
		{
			if (i == 0)
				cout << "0.";
			else
				cout << 0;
		}
		for (int i = 0; i < re.size(); i++)
			cout << re[i];
	}
	else
	{
		if (e_num < (re.size() - 1))//表示有小数点
		{
			for (int i = 0; i < re.size(); i++)
			{
				if (i == e_num)//小数点位置
					cout << re[i] << '.';
				else
					cout << re[i];
			}
		}
		else//无小数点，要补0
		{
			for (int i = 0; i < re.size(); i++)
				cout << re[i];

			int cnt = e_num - re.size() + 1;
			while (cnt > 0)
			{
				cout << 0;
				cnt--;
			}
		}
	}
	cout << endl;
	
	return 0;
}

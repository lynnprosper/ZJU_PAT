#include<iostream>
#include<string>
#include<algorithm> //使用reverse函数
using namespace std;

string Add(string &s1, string &s2);	//两个数的加法

/*
题意：给定步骤，判断回文问题。
基本运算题。
由于数据比较大，长整型无法满足运算，必须用字符串
实现加法。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	string s1;
	int step;
	cin >> s1 >> step;

	int i;
	string s2;
	for (i = 0; i < step; i++)
	{
		s2 = s1;
		reverse(s2.begin(), s2.end());	//逆置原数

		if(s1 == s2)	//判断是否回文
			break;
		else
			s1 = Add(s1, s2);
		
	}

	cout << s1 << '\n' << i << endl;

	return 0;
}

string Add(string &s1, string &s2)
{
	string result;	//存储结果
	int carry = 0 ;	//存储进位，进位只可能是0或1
	for(int i = s1.size()-1; i >= 0; i--)
	{
		int sum = s1[i] -'0' + s2[i] - '0' + carry;	//模拟加法
		if(sum < 10)
		{
			result.insert(result.begin(), sum+'0');
			carry = 0;
		}
		else
		{
			result.insert(result.begin(), sum-10+'0');
			carry = 1;
		}
	}

	if(carry)
		result.insert(result.begin(), carry+'0');	//有进位

	return result;
}

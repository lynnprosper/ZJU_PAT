#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
题意：输出一个数的拼音读法。
思路：
需要讨论各种情况，分析读法。
1. 0的情况，直接输出ling。
2. 剩下的是数字0所处的位置。分为是在边上还是夹在数字之间。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	string wgt[9] = { "", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi" };//存储位权
	string number[10] = { "ling", "yi", "er", "san", "si",
		"wu", "liu", "qi", "ba", "jiu" };//存储数字的拼音
	int zeroFlag = 0;//判断是否夹在非0数字间
	int negtiveFlag = 0;//判断正负
	string num;//待判断字符

	cin >> num;
	if (num == "0")//特殊情况0
	{
		cout << "ling" << endl;
		return 0;
	}

	if (num[0] == '-')//负数
	{
		negtiveFlag = 1;
		num.erase(0, 1);
	}

	stack<string> result;//倒着来，用栈存储
	int i, j;
	for (i = num.length()-1, j = 0; i >= 0; i--, j++)
	{
		if (num[i] == '0')
		{
			if (zeroFlag == 1 && num[i + 1] != '0')//表示需要读出ling
				result.push(number[0]);
			if (j == 4)//此次要输出位权“Wan"
				result.push(wgt[j]);
		}
		else if (num[i] != '0')
		{
			zeroFlag = 1;
			if (j != 0)
				result.push(wgt[j]);
			result.push(number[num[i] - '0']);
		}
	}
	if (negtiveFlag == 1)
	{
		result.push("Fu");
	}

	int flag = 0;
	while (!result.empty())//输出
	{
		if (flag == 1)
			cout << ' ';
		else
			flag = 1;
		cout << result.top();
		result.pop();
	}
	cout << endl;

	return 0;
}

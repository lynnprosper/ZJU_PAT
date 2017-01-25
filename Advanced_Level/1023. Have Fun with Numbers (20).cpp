#include<iostream>
#include<string>
using namespace std;

/*
题意：判断一个数的2倍所含有的数字是否和原来的相同。
思路：
基本运算题。
由于一个数可能有20位，只能用字符串string处理了。
2倍也要自己模拟乘法。最后用两个表示数位的数组，判断
每个元素是否相等。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	string origin, result;	//分别存储原始数、2倍后的数
	int ori[10] = {0};	//0~9的数位值
	int res[10] = {0};

	cin >> origin;
	result = origin;
	int add = 0;	//表示进位，可能为1；
	for(int i = result.size()-1; i >= 0; i--)	//模拟乘法
	{
		int tem = result[i] - '0';
		int mul = 2*tem + add;
		if(mul > 9)
		{
			result[i] = mul - 10 + '0';
			add = 1;
		}
		else
		{
			result[i] = mul + '0';
			add = 0;
		}
	}

	if(add != 0)	//两个数位数不同，输出no
	{
		string re = "0";
		re[0] += add;
		re += result;	//把result添加到re后面
		cout << "No\n" << re <<endl;
	}
	else
	{
		for(unsigned i = 0; i < origin.size(); i++)	//判断是否相同
		{
			int index = origin[i] - '0';
			int index2 = result[i] - '0';
			ori[index]++;
			res[index2]++;
		}

		int flag = 0;
		for(int i = 0; i < 10; i++)
		{
			if(ori[i] != res[i])
			{
				flag = 1;
				break;
			}
		}

		if(flag)	//输出
			cout << "No\n" << result <<endl;
		else
			cout << "Yes\n" << result << endl;
	}

	return 0;
}

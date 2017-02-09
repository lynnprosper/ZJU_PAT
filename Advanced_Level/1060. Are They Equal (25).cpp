#include<iostream>
#include<string>
using namespace std;

int N;//精度
string sa, sb;
int getExp(string &s, string &re);//返回指数，第二个参数是处理后得到的尾数

/*
题意：
转换成类似科学记数法的形式，并比较是否相等。
思路：
字符串处理题。坑比较多。
若相等，则指数和尾数都要相等。
核心是如何获得指数和尾数。
要点：
1. 给出的数可能是0，或00这种（最后一个测试点）。
2. 可能有前导0， 如00123
3. 可能为小数， 如0.123或0.00123.
处理字符串我用的stl中的string，也可以用char。
已AC。
部分测试点参考自: http://blog.csdn.net/xyt8023y/article/details/47086811
感谢博主。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	cin >> N >> sa >> sb;

	string re1, re2;//存储尾数
	int epa = getExp(sa, re1);//存储指数
	int epb = getExp(sb, re2);

	if (epa == epb && re1 == re2)//输出
		cout << "YES 0." << re1 << "*10^" << epa << endl;
	else
	{
		cout << "NO 0." << re1 << "*10^" << epa
			<< " 0." << re2 << "*10^" << epb << endl;
	}

	return 0;
}

int getExp(string &s, string &re)//返回指数，第二个参数是处理后得到的尾数
{
	int point_pos = -1, first_pos = -1;//分别是小数点位置， 第一个非0位置
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0' && first_pos == -1)//前导0跳过
			continue;
		else if (s[i] == '.')
			point_pos = i;
		else
		{
			if (first_pos == -1)
				first_pos = i;
			if (re.size() < N)//尾数存入字符串
				re.push_back(s[i]);
			
		}
	}

	int i = re.size();
	while (i < N)//不够，后面添0
	{
		re.push_back('0');
		i++;
	}

	if (first_pos == -1)//表示全为0，返回指数0.
		return 0;

	if (point_pos == -1)//无小数点
		point_pos = s.size();

	if (point_pos > first_pos)
		return (point_pos - first_pos);
	else
		return (point_pos + 1 - first_pos);//为小数，小数点占一位，需特殊处理。
}

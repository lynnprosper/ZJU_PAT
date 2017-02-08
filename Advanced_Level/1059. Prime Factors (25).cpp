#include<iostream>
#include<algorithm>//使用sqrt函数
#include<map>
using namespace std;

/*
题意：
将一个数进行分解成质因数，从小到大输出。
思路：
题目不难。有多种方法。
可以先建立2~根号N的素数表，然后试除。
亦或判断下一个素数的方法处理。
我采用的边除边判断，并把质因数保存到map里。这样
绕了远路了。
注意1的特例。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int x, i;
	cin >> x;
	cout << x << '=';
	map<int, int> fac;//key是素数，value是指数。
	if (x == 1)//1的特例
	{
		cout << 1 << endl;
		return 0;
	}

	while (x > 1)
	{
		int flag = 0;//是否可分解的标志位
		int limit = (int)sqrt(double(x));
		for (i = 2; i <= limit; i++)//循环
		{
			if (x % i == 0)
			{
				x /= i;
				if (fac.count(i) == 0)
					fac[i] = 0;
				fac[i]++;
				flag = 1;
				break;
			}
		}

		if (flag == 0)//0表示已无法再分解。
		{
			if (fac.count(x) == 0)
				fac[x] = 0;
			fac[x]++;
			break;
		}
	}

	map<int, int>::iterator it;//输出
	for (it = fac.begin(); it != fac.end(); it++)
	{
		if (it == fac.begin())
		{
			if (it->second == 1)
				cout << it->first;
			else
				cout << it->first << '^' << it->second;
		}
		else
		{
			if (it->second == 1)
				cout << '*' << it->first;
			else
				cout << '*' << it->first << '^' << it->second;
		}
	}
	cout << endl;

	return 0;
}

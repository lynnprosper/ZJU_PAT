#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

string a, b, c;
void calc();
/*
题意：字符串处理。
给出一个数a，判断多少步可以计算出一个回文。
打印出计算过程。
比较简单，写个加法函数就好了。
已AC.
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> a;
	b = a;
	reverse(b.begin(), b.end());
	int cnt = 0;
	while (1)
	{
		if (a == b)
		{
			cout << a << " is a palindromic number." << endl;
			break;
		}
		else if (cnt == 10)
		{
			cout << "Not found in 10 iterations." << endl;
			break;
		}
		
		calc();
		cout << a << " + " << b << " = " << c << endl;
		a = b = c;
		reverse(b.begin(), b.end());
		cnt++;
	}

	return 0;
}

void calc()
{
	int cat = 0, ba;
	c.clear();
	for (int i = 0; i < a.size(); i++)
	{
		ba = (a[i] - '0' + b[i] - '0' + cat) % 10;
		cat = (a[i] - '0' + b[i] - '0' + cat) / 10;
		c.push_back(ba + '0');
	}
	if (cat > 0)
		c.push_back('1');

	reverse(c.begin(), c.end());
}

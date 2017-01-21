#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int isPrime(int x);	//判断是否素数
int Reverse(int x, int d);	//对数反转

int main()
{
	//freopen("in.txt", "r", stdin);
	int N;	//待判断数
	int D;	//进制
	int flag;	//标志位，1输出yes

	cin >> N;
	while(N > 0)
	{
		flag = 0;
		cin >> D;
		if(isPrime(N))
		{
			if(isPrime(Reverse(N, D)))
				flag = 1;
		}
		
		if(flag)
			cout << "Yes" <<endl;
		else
			cout << "No" << endl;

		cin >> N;
	}

	return 0;
}

int isPrime(int x)//判断是否素数
{
	if(x == 1) return 0;
	int y = (int)sqrt(double(x));
	for(int i = 2; i <= y; i++)
	{
		if(x % i == 0)
			return 0;
	}

	return 1;
}

int Reverse(int x, int d)//对数反转
{
	vector<int> dv;
	while(x)
	{
		dv.push_back(x%d);
		x /= d;
	}

	int y = 0;
	int base = 1;
	vector<int>::reverse_iterator it;	//反向迭代器
	for(it = dv.rbegin(); it != dv.rend(); it++)	//转换成十进制
	{
		y += *it * base;
		base *= d;
	}

	return y;	//返回反转的十进制数
}

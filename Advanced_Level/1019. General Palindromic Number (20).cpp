#include<iostream>
#include<vector>
using namespace std;

unsigned N, b;	//分别表示待求数， 给定进制。
vector<unsigned> num;	//存储转换的数位
void Convert();	//转换函数

/*
题意：
判断一个十进制数在某进制下是否回文。基本逻辑题。
思路：
先进行进制转换，然后判断即可。
此处使用了vecto容器。
注意0的特殊情况。
*/
int main()
{
	freopen("in.txt", "r", stdin);
	cin >> N >> b;
	Convert();

	return 0;
}

void Convert()
{
	while(N)	//进行转换，此时保存在数组的是逆向的数位
	{
		int tem = N % b;
		num.push_back(tem);
		N /= b;
	}

	int flag = 1;	//判断标志
	int j = num.size()-1;
	for(int i = 0; i < j; i++, j--)	//判断是否回文
	{
		if(num[i] != num[j])
			flag = 0;
	}

	if(flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	if(!num.empty())
	{
		vector<unsigned>::reverse_iterator rit;	//逆向迭代器
		for(rit = num.rbegin(); rit != num.rend(); rit++)
		{
			if(rit == num.rbegin())
				cout << *rit;
			else
				cout << " " << *rit;
		}
	}
	else
		cout << 0;

	cout << endl;
}

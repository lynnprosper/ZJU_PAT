#include <iostream>
#include <set>
#include <string>
using namespace std;

/*
题意：字符处理题。求出每个数字的和，然后从小到大输出。
思路：
有多个方法，可以作为数字，也可以作为字符串处理。
我把每个数作为字符串处理，累计求和。然后存入set里（利用有序原则，且不重复）。
最后输出set里的数字就好了。
已AC。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int N;
	cin >> N;
	set<int> s;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		int sum = 0;
		for (int j = 0; j < str.size(); j++)
		{
			sum += str[j] - '0';//累加求和
		}
		s.insert(sum);//插入set
	}

	cout << s.size() << endl;
	set<int>::iterator iter = s.begin();
	int flag = 0;
	for (iter; iter != s.end(); iter++)//输出
	{
		if (flag != 0)
			cout << ' ';
		cout << *iter;
		flag = 1;
	}

	return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
题意：字符串处理题。给出一段字符串，判断某个按键是坏的。
思路：
可以用map映射。我用的数组char进行映射。
先找出哪些按键是坏的，记录在一个数组stucked[]里。
然后对字符串遍历，如果是坏的，直接往前移动k个字符，只输出一个坏的。
已AC。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int K;//按键重复出现的个数
	string str;
	cin >> K >> str;
	str.push_back('A');//加入字符A,为了后面便于遍历。
	int stucked[128] = { 0 };//存储坏的。
	int worked[128] = { 0 };//存储正常的
	vector<char> sv;//用于输出坏的按键。

	int cnt = 1;
	int i = 1;
	while (i < str.size())
	{
		while (str[i] == str[i - 1] && i < str.size())//相同的
		{
			cnt++;
			i++;
		}

		if (cnt % K == 0 && worked[str[i - 1]] == 0)//重复出现，且不正常
		{
			sv.push_back(str[i - 1]);//压入容器
		}
		else
			worked[str[i - 1]] = 1;//正常的按键

		cnt = 1;
		i++;
	}

	for (int i = 0; i < sv.size(); i++)//输出坏的
	{
		if (worked[sv[i]] == 0)
		{
			cout << sv[i];
			stucked[sv[i]] = 1;//该按键是坏的。
			worked[sv[i]] = 1;//输出一个之后，置为1，以防后面重复输出。
		}
	}
	cout << endl;

	int j = 0;
	while (j < str.size() - 1)//最后一个字符是检验的，不遍历。
	{
		if (stucked[str[j]] == 0)//好的
		{
			cout << str[j];
			j++;
		}
		else
		{
			cout << str[j];//坏的，j前移k个
			j += K;
		}
	}
	
	cout << endl;
}

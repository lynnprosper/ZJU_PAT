#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

/*
题意：字符处理题，判断哪个键坏了。
思路：把显示出的字符逐一和原始字符比较即可。
我用了一个set，存储已经坏掉的键。
已AC.
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	string origin, display;
	cin >> origin >> display;
	set<char> broke;	//存储已经坏掉的键。
	int i, j;
	for (i = 0, j = 0; i < origin.length() && j < display.length(); i++)
	{
		if (origin[i] != display[j])//循环判断
		{
			char temp = toupper(origin[i]);//转换成大写
			if (broke.count(temp) == 0)
			{
				cout << temp;
				broke.insert(temp);
			}
		}
		else
		{
			j++;
		}
	}

	while (i < origin.length())//判断剩下的。
	{
		char temp = toupper(origin[i]);
		if (broke.count(temp) == 0)
		{
			cout << temp;
			broke.insert(temp);
		}
		i++;
	}
	cout << endl;

	return 0;
}

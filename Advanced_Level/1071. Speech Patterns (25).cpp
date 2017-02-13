#include<iostream>
#include<string>
#include<sstream>//使用字符串流， 用于转换成单词
#include<cctype>//使用iisalnum函数， 判断是否字母或数字
#include<map>
using namespace std;

/*
题意：输出一行字符串中出现频率最高的单词及次数（不区分大小写）。
思路：
先把字符串保存到string s里，
然后遍历每个字符，不是字母或数字，置为空格。
然后把s读入字符串流ss里，输出每个单词，插入map。
其中map的key是单词，value是次数。
最后输出即可。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	string s;
	getline(cin, s);//读入一行
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = tolower(s[i]);//转换成小写
		if (!isalnum(s[i]))
			s[i] = ' ';//无效字符，置为空格
	}

	string re;//保存结果的单词
	int cnt = 0;
	map<string, int> word;
	stringstream ss(s);//字符串流ss
	while (ss >> s)//字符串流一次读出一个单词，遇到空格截止。
	{
		if (word.count(s) == 0)
			word[s] = 0;
		word[s]++;

		if (cnt < word[s])//记录最大次数
		{
			cnt = word[s];
			re = s;
		}
		else if (cnt == word[s] && s < re)
			re = s;
	}
	cout << re << ' ' << cnt << endl;

	return 0;
}

#include<iostream>
#include<string>
using namespace std;

const int Max = 100;//最大行数

/*
题意：求所有文本行的共同后缀。
思路：
利用stl中的string遍历就好了。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N;
	cin >> N;
	getchar();//吸收换行符
	string s[Max];//存储文本行
	int len[Max];//每行的长度

	for (int i = 0; i < N; i++)//读入数据
	{
		getline(cin, s[i]);
		len[i] = s[i].size();
	}

	string re;//存储后缀字符
	for (int i = len[0] - 1; i >= 0; i--)
	{
		char ch = s[0][i];
		int j, flag = 1;//flag为是否有共同后缀的标记
		for (j = 1; j < N && len[j] > 0; j++)
		{
			len[j]--;
			if (s[j][len[j]] != ch)//无共同后缀
			{
				flag = 0;
				break;
			}
		}

		if (flag == 1 && j == N)//是共同后缀
			re.push_back(ch);
		else
			break;
	}

	if (re.empty())
		cout << "nai" << endl;
	else
	{
		string sre(re.rbegin(), re.rend());//字符串要逆序
		cout << sre << endl;
	}

	return 0;
}

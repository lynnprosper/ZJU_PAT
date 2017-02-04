#include<iostream>
#include<algorithm>//使用sort函数
#include<vector>
using namespace std;

const int Max = 2501;//最大课程数
int toId(char *s);//名字转换成数字id
void toName(int id, char *s);//数字转换成名字

/*
题意：
输出每个课程的学生名字。比较简单。
思路：
此题关键是处理超时问题。
所以要把名字转换成数字来存储，用字符串超时。
剩下的就是把每个课程的学生名字压入vector里面，再排序输出。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N, K;
	scanf("%d %d", &N, &K);
	vector<int> cou[Max];//存储每个课程的学生名字

	char name[5];
	int c;
	for (int i = 0; i < N; i++)
	{
		scanf("%s %d", name, &c);
		for (int j = 0; j < c; j++)
		{
			int id;
			scanf("%d", &id);
			cou[id].push_back(toId(name));//压入vector
		}
	}

	for (int i = 1; i <= K; i++)//输出
	{
		int size_s = cou[i].size();
		if (size_s != 0)
		{
			sort(cou[i].begin(), cou[i].end());//先排序
			printf("%d %d\n", i, size_s);
			for (int j = 0; j < size_s; j++)
			{
				toName(cou[i][j], name);
				printf("%s\n", name);
			}
		}
		else
			cout << i << ' ' << 0 << endl;
	}

	return 0;
}

int toId(char *s)//名字转换成数字id
{
	int id = s[3] - '0';
	id += (s[2] - 'A') * 10 + (s[1] - 'A') * 260 + (s[0] - 'A') * 260*26;
	return id;
}

void toName(int id, char *s)//数字转换成名字
{
	s[4] = '\0';
	s[3] = id % 10 + '0';
	s[2] = id % 260/10 + 'A';
	s[1] = id / 260 % 26 + 'A';
	s[0] = id / 260 / 26 + 'A';
	return;
}

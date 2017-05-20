#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool isPrime(int x);//判断是否素数

/*
题意:基础逻辑题。
按照给定规则，判断某些查询的人该领取的奖项。
思路：
由于要对id随机查询，很容易想到用map。
利用map，把每个人的id和排名存到map里。
查询的时候检查该id的排名，根据排名输出奖项，同时排名设为-1.
这样为了重复访问时输出已领取的相关信息。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int N;
	cin >> N;
	map<int, int> rank;
	for (int i = 1; i <= N; i++)//读入数据
	{
		int id;
		cin >> id;
		rank[id] = i;
	}

	int K;
	cin >> K;
	for (int i = 0; i < K; i++)//进行判断
	{
		int testId;
		cin >> testId;
		if (rank.count(testId) != 0)//该id存在
		{
			if (rank[testId] < 1)//说明已领取
			{
				printf("%04d: Checked\n", testId);
			}
			else if (rank[testId] == 1)// 第一名
			{
				printf("%04d: Mystery Award\n", testId);
				rank[testId] = -1;
			}
			else if (isPrime(rank[testId]))//是素数
			{
				printf("%04d: Minion\n", testId);
				rank[testId] = -1;
			}
			else
			{
				printf("%04d: Chocolate\n", testId);
				rank[testId] = -1;
			}
		}
		else
		{
			printf("%04d: Are you kidding?\n", testId);
		}
	}

}

bool isPrime(int x)//判断素数
{
	if (x == 1)
		return false;

	for (int i = 2; i <= (int)sqrt(double(x)); i++)
	{
		if (x % i == 0)
			return false;
	}

	return true;
}

#include<iostream>
#include<vector>
using namespace std;

/*
题意：
不得不说，每个单词都认识，读了n遍就是没读懂题（摊手）。
还是对照着输入说吧。第一行两个数分别为总人数，一个组的pk人数。
第二行对应着编号从0~N-1的参赛者在游戏里获得的分数（可以这么理解）。
第三行对应着分组顺序。即 6 0 8（参赛者编号）为一组，6号的分数为19， 8号晋级。
类似地，7 10 15一组， 7号晋级。
9 1 4一组，9号晋级。
2 3一组（不满一组分在一组），3号晋级。总共4个人晋级，那么未晋级的排名都是5.即未晋级排名是晋级人数+1.
用算法模拟上述过程就好了。
用vector保存每次晋级的编号。
直到vector只有1个。
嗯，读懂题比写代码还难。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int np, ng;//总人数， 每组人数
	cin >> np >> ng;
	vector<int> wgt(np), list(np), rank(np);//分别为分数， pk的人员编号， 排名
	for (int i = 0; i < np; i++)
		cin >> wgt[i];
	for (int i = 0; i < np; i++)
		cin >> list[i];

	while (list.size() > 1)//pk人数=1跳出循环
	{
		int now_rank = list.size() / ng + 1;//目前的排名
		if (list.size() % ng > 0)//有多余的要+1
			now_rank++;

		vector<int> pro;//存储晋级的人员
		int i = 0;
		while (i < list.size())
		{
			int max = -1;
			int m_id;
			for (int j = 0; j < ng && i < list.size(); j++, i++)//找出晋级人员
			{
				rank[list[i]] = now_rank;//排名赋值
				if (wgt[list[i]] > max)
				{
					max = wgt[list[i]];
					m_id = list[i];
				}
			}

			pro.push_back(m_id);
		}
		list = pro;
	}
	rank[list[0]] = 1;//第一名

	for (int i = 0; i < np; i++)
	{
		if (i == 0)
			cout << rank[i];
		else
			cout << ' ' << rank[i];
	}
	cout << endl;

	return 0;
}

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
数据处理统计题，比较繁琐。
题意是计算用户的月有效费用。
可以构建结构体，然后排序。
为求简便，这里使用map， 利用map的有序性。
注：已AC。
PS2：数据有效性，若1on， 2 on， 3 off， 则1会被抛弃。
无有效记录不输出。
*/

struct Node//每条记录的结构体
{
	bool operator< (const Node &b)
	{
		return (startTime < b.startTime);
	}
	Node(int s, int mo, int d, int h, int m, int t) : startTime(s), month(mo), dd(d),hh(h), mm(m),tag(t) {}
	int startTime;//记录的时间
	int month, dd, hh, mm;
	int tag;//0表示on-line, 1 for off-line
};

int main()
{
	freopen("in.txt", "r", stdin);
	int fare[24];
	for (int i = 0; i < 24; i++)
	{
		scanf("%d", &fare[i]);
	}
	int N;
	scanf("%d", &N);

	map<string, vector<Node> > mp;// 一个人一个vector，存储他的记录
	for (int i = 0; i < N; i++)
	{
		char tmp[25] = { 0 };
		char status[10];
		int month, dd, hh, mm;
		scanf("%s %d:%d:%d:%d %s", tmp, &month, &dd, &hh, &mm, status);
		string name(tmp);
		int start = dd * 1440 + hh * 60 + mm;
		int tag = (status[1] == 'n' ? 0 : 1);
		Node tNode(start, month, dd, hh, mm, tag);

		if (mp.count(name) > 0)
		{
			mp[name].push_back(tNode);
		}
		else
		{
			vector<Node> mv;
			mv.push_back(tNode);
			mp.insert(make_pair(name, mv));
		}
	}

	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		int flag = 0;//标记是否输出该人记录，无有效通话不输出
		int Tat = 0;//该人的总金额
		sort(it->second.begin(), it->second.end());

		int size = it->second.size();
		for (int i = 0; i < size; )
		{
			if (it->second[i].tag == 0)
			{
				for (int j = i + 1; j < size; j++)
				{
					if (it->second[j].tag == 0)
					{
						i = j;
						break;
					}
					else//找到两条配对的记录
					{
						int total = 0;
						int duration = it->second[j].startTime - it->second[i].startTime;
						
						int hhs = it->second[i].dd * 24 + it->second[i].hh + 1;
						int hhe = it->second[j].dd * 24 + it->second[j].hh;
						if (hhs > hhe)//这里表示开始和结束的小时一样，单独处理
						{
							total += (it->second[j].mm - it->second[i].mm) * fare[it->second[i].hh];
						}
						else
						{
							total += (60 - it->second[i].mm) * fare[it->second[i].hh];
							total += (it->second[j].mm) * fare[it->second[j].hh];
						}

						for (int k = hhs; k < hhe; k++)
						{
							total += 60 * fare[k % 24];
						}
						Tat += total;
						if (flag == 0)
						{
							printf("%s %02d\n", it->first.c_str(), it->second[0].month);
							flag = 1;
						}
						printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
							it->second[i].dd, it->second[i].hh, it->second[i].mm,
							it->second[j].dd, it->second[j].hh, it->second[j].mm,
							duration, total / 100.0);

						i = j + 1;
						break;
					}
				}

				if (i == size - 1)
					i++;
			}
			else
			{
				i++;
			}
		}

		if (flag == 1)
			printf("Total amount: $%.2f\n", Tat / 100.0);
	}

	return 0;
}

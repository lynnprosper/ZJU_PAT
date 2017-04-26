#include<iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Item		//存储车辆信息的结构体
{
	bool operator< (const Item &b) const//字符串-->时间的升序排序
	{
		if (m_name < b.m_name)
			return true;
		else if (m_name == b.m_name)
		{
			if (m_time < b.m_time)
				return true;
			else
				return false;
		}
		else
			return false;
	}

	string m_name;//存储名字
	int m_time;//存储进出时间
	bool m_in;//标志是否进的状态
	bool m_valid;//信息有效的状态
};
bool CmpTime(const Item &a, const Item &b)//对结构体按照进出时间排序
{
	if (a.m_time < b.m_time)
		return true;
	else
		return false;
};

/*
题意： 结构体排序问题
给出车辆的进出信息，统计每个时间段的停车场车辆数以及最长停车时间和id。
注意，车辆信息可能是无效的。一个进唯一地和紧接着的出进行配对，否则无效。
思路：此题复杂在需要统计停车的最长时间。
为了便于处理，把时间转换成秒。
1），对结构体先按照id，再按照进出时间排序。
2）对数组遍历。剔除无法配对的数据，我采用的是设置状态位，
也可以把有效数据存储到一个新的数组。
同时寻找最大的停车时间maxTime，把相应的id加入一个set中。
3）查询某段时间的车辆数。
	因为查询时间是顺序，所以先按照时间排序，一次遍历即可。
	最后输出set中的数据即可（set默认是升序存储数据）。
已AC.
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N, M;
	cin >> N >> M;

	vector<Item> itemVec;//存储车辆信息的数组
	for (int i = 0; i < N; i++)//读入数据
	{
		Item temInfo;
		string symbol;
		int hh, mm, ss;
		char a, b;
		cin >> temInfo.m_name >> hh >> a >> mm >> b >> ss >> symbol;

		temInfo.m_time = hh * 3600 + mm * 60 + ss;
		temInfo.m_in = (symbol == "in" ? true : false);//设置状态位
		itemVec.push_back(temInfo);
	}
	sort(itemVec.begin(), itemVec.end());//字符串-->时间的升序排序

	int i = 0;
	string lastName;//存储上一个车的id，初始空
	int lastTime = 0;//存储已停时间，便于累计
	int maxTime = 0;//存储最大停车时间
	set<string> maxTimeCar;
	while (i < N)//遍历
	{
		if (i == N - 1)//无法配对，无效
		{
			itemVec[i].m_valid = false;
			break;
		}

		if (itemVec[i].m_name == itemVec[i + 1].m_name)
		{
			if (itemVec[i].m_in && !itemVec[i + 1].m_in)//可以配对
			{
				itemVec[i].m_valid = itemVec[i + 1].m_valid = true;
				
				int curTime;
				if (itemVec[i].m_name == lastName)
				{
					curTime = itemVec[i + 1].m_time - itemVec[i].m_time + lastTime;
					lastTime = curTime;
				}
				else
				{
					curTime = itemVec[i + 1].m_time - itemVec[i].m_time;
					lastName = itemVec[i].m_name;
					lastTime = curTime;
				}

				if (curTime > maxTime)//更新最大停车时间
				{
					maxTime = curTime;
					maxTimeCar.clear();
					maxTimeCar.insert(itemVec[i].m_name);//加入set
				}
				else if (curTime == maxTime)
				{
					maxTimeCar.insert(itemVec[i].m_name);
				}

				i += 2;
			}
			else
			{
				itemVec[i].m_valid = false;
				i++;
			}
		}
		else
		{
			itemVec[i].m_valid = false;
			i++;
		}
	}

	int j, curNum;
	curNum = j = 0;
	sort(itemVec.begin(), itemVec.end(), CmpTime);//按照时间升序，
	for (int i = 0; i < M; i++)
	{
		int hh, mm, ss;
		char a, b;
		cin >> hh >> a >> mm >> b >> ss;
		int temTime = hh * 3600 + mm * 60 + ss;
		for (j; j < N && itemVec[j].m_time <= temTime; j++)
		{
			if (itemVec[j].m_valid)
			{
				if (itemVec[j].m_in)//进，数目加1
				{
					curNum++;
				}
				else
				{
					curNum--;//出，数目减1
				}
			}
		}

		printf("%d\n", curNum);//cout超时，最好统一，不要混用
	}

	set<string>::iterator setIter;
	for (setIter = maxTimeCar.begin(); setIter != maxTimeCar.end(); setIter++)
	{
		cout << *setIter << ' ';//输出id
	}
	int hh = maxTime / 3600;
	int mm = maxTime % 3600 / 60;
	int ss = maxTime % 60;
	printf("%02d:%02d:%02d\n", hh, mm, ss);//输出最大时间

	return 0;
}

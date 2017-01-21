#include<iostream>
#include<string>
#include<sstream>	//字符串流
#include<map>
#include<iomanip>
using namespace std;

const string on("on-line");
const string off("off-line");

/*
数据处理统计题，比较繁琐。
题意是计算用户的月有效费用。
可以构建结构体，然后排序。
为求简便，这里使用map， 利用map的有序性。
注：该代码最后一个测试点未AC，欢迎指正。
PS2：数据有效性，若1on， 2 on， 3 off， 则1会被抛弃。
无有效记录不输出。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int rate[24];	//存储计费标准
	int N;
	for(int i = 0; i < 24; i++)
		cin >> rate[i];
	cin >> N;

	string id, time, flag;
	map<string, map<string, string> > data;	//map里的键值是一个map，存储每个id的记录；
	for(int i = 0; i < N; i++)
	{
		cin >> id >> time >> flag;
		if(data.count(id))	//id是key
		{
			data[id][time] = flag;
		}
		else
		{
			map<string, string> info;	//第一次，插入map；此时map的key是日期时间
			info[time] = flag;
			data[id] = info;
		}
	}

	map<string, map<string, string> >::iterator it;	//迭代器；
	string time1, time2;
	for(it = data.begin(); it != data.end(); it++)//循环统计每个用户，删除无效记录
	{
		id = it->first;
		map<string, string>::iterator it2, it3;
		it2 = data[id].begin();
		while(it2 != data[id].end())	//处理每个用户的通话记录
		{
			it3 = it2;	//迭代器3起辅助作用，以防删除时2失效。
			if(it2->second == on)
			{
				it3++;
				if(it3 != data[id].end() && it3->second == off)
				{
					it2 = ++it3;
				}
				else
				{
					data[id].erase(it2);	//删除无效记录
					it2 = it3;
				}
			}
			else
			{
				data[id].erase(it2++);	//删除无效记录
			}
		}

		if(!data[id].empty())	//非空，有有效记录
		{
			it2 = data[id].begin();
			cout << id << ' ' << it2->first.substr(0, 2) << endl;	//输出名字，月份

			double total = 0;	//总费用
			while(it2 != data[id].end())
			{
				time1 = it2->first;	//通话开始时间
				it2++;
				time2 = it2->first;	//通话结束时间
				it2++;
				time1[2] = time1[5] = time1[8] = ' ';
				time2[2] = time2[5] = time2[8] = ' ';

				int month, d1, d2, h1, h2, m1, m2;
				stringstream s1(time1);
				stringstream s2(time2);
				s1 >> month >> d1 >> h1 >> m1;	//写入月日时分
				s2 >> month >> d2 >> h2 >> m2;
				int timeOn = m1+ h1*60 + d1*1440;	//通话开始分钟
				int timeOff = m2+ h2*60 + d2*1440;
				int sum_m = timeOff - timeOn;	//通话总时间

				double money = 0;	//每次通话的金额
				int hourOn = h1 + d1*24;
				int hourOff = h2 + d2*24;
				money = (60-m1)*rate[h1] + m2*rate[h2];	//先累加两端
				for(int i = hourOn+1; i < hourOff; i++)	//累计费用
				{
					money += 60*rate[i%24];
				}
				total += money;

				cout << setw(2) << setfill('0') << d1 <<':'	//输出
					<< setw(2) << setfill('0') <<h1 << ':'
					<< setw(2) << setfill('0') << m1
					<< ' ' << setw(2) << setfill('0') << d2 << ':' 
					<< setw(2) << setfill('0') << h2 << ':' 
					<< setw(2) << setfill('0') << m2
					<< ' ' << sum_m << " $" <<fixed << setprecision(2) << money/100 << endl;
			}
			cout << "Total amount: $" << fixed << setprecision(2) << total/100 << endl;
		}
	}

	return 0;
}

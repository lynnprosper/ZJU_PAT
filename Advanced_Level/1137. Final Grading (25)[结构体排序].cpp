#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Node
{
	bool operator< (const Node &b)	//**重载比较运算符
	{
		if (gg == b.gg)
		{
			return (name < b.name);
		}
		else
			return (gg > b.gg);
	}
	Node() :gp(-1), gm(-1), gf(-1), gg(0){}
	string name;
	int gp, gm, gf, gg;
};

/*
题意：结构体排序
给出学生成绩，输出符合要求的成绩即可。
用到了map容器。
注意：题目中要求最终成绩>=60, 不是final（期末成绩）。
我在这里卡了很久（最后一个测试点）。
已AC。
*/

int P, M, N;
map<string, Node> mp;

int main()
{
	ios::sync_with_stdio(false);
	freopen("in.txt", "r", stdin);
	cin >> P >> M >> N;
	string ts;
	int tg;
	for (int i = 0; i < P; i++)
	{
		cin >> ts >> tg;
		if (tg > 199)	//保存符合条件的
		{
			Node tn;
			tn.gp = tg;
			tn.name = ts;
			mp.insert(make_pair(ts, tn));
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> ts >> tg;
		auto it = mp.find(ts);
		if (it != mp.end())
		{
			it->second.gm = tg;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> ts >> tg;
		if (1)
		{
			auto it = mp.find(ts);
			if (it != mp.end())
			{
				
				it->second.gf = tg;
				if (it->second.gm < it->second.gf)
					it->second.gg = it->second.gf;
				else
					it->second.gg = ((float(it->second.gm) * 0.4) + (float(it->second.gf) * 0.6) + 0.5);
			}
		}
	}
	vector<Node> re;
	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		if (it->second.gg >= 60)
			re.push_back(it->second);
	}

	sort(re.begin(), re.end());
	for (auto it = re.begin(); it != re.end(); it++) //输出结果
	{
		cout << it->name << " " << it->gp << ' '
			<< it->gm << ' ' << it->gf << ' ' << it->gg << endl;
	}

	return 0;
}

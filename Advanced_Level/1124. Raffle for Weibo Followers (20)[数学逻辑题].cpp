#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

/*
题意：数学逻辑题。给出转发的人名单，每隔m个输出。
其中已经中奖的人不计入m。
思路：
关键点是在遍历的时候判断某人是否已经中过奖。
所以这里采用了set，中过奖的压入set里，以便方便查询。
剩下的就是每隔m个输出了。
已AC。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int N, M, S;
	cin >> N >> M >> S;
	vector<string> name(N+1);//存放名单，从1开始存
	set<string> ns;//存放中过奖的名单

	for (int i = 1; i <= N; i++)//读入数据
	{
		cin >> name[i];
	}

	if (S > N)//特殊情况
		cout << "Keep going..." << endl;
	else
	{
		cout << name[S] << endl;
		ns.insert(name[S]);

		int flag = 0;
		for (int i = S + 1; i <= N; i++)
		{
			if (ns.count(name[i]) == 0)//该人未中过奖
			{
				flag++;
				if (flag == M)
				{
					cout << name[i] << endl;
					ns.insert(name[i]);
					flag = 0;
				}
			}	
		}
	}

	return 0;
}

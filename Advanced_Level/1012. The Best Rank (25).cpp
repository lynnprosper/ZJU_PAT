#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct Node	//用来保存四种成绩的排名，A映射0，以此类推。
{
	int rank[4];
};

/*
思路：题意是求每个学生的多个成绩的最佳排名。说到这里，有一个
巨大的坑，会影响你AC。想起这儿，心都碎了，d了好多次。结果的排名形式是
相同成绩排名相同，但不同成绩不是排名的简单递增，而是总人数的排名。
比如正确的排名是1,2,2,3，3，6. 而不是“1,2,2,3,3,4”。
题目考查对数据的处理。我想到了两种方法。可以用结构数组，然后分别排序4次，选出最佳排名。
也可以直接用map，利用map的数据有序性。

为求简便，采用STL中的map，构建4个map，对应着平均成绩A,
计算机成绩C，数学M, 英语E.最后再遍历一次，把结果保存到一个map中。

两种方法最后的结果都要保存到map中，因为学生id很大，只有利用map的映射关系，
快速读取结果。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int i, N, M;
	map<int, vector<int>, greater<int> > mp[4];	//4个map，map默认是关键字升序；
	//此处用内置的降序仿函数；关键字是成绩，所以键值可能有多个，采用vector；
	int score[4];
	int id;
	cin >> N >> M;
	for(i = 0; i < N; i++)	//输入数据；
	{
		cin >> id >> score[1] >> score[2] >> score[3];
		score[0] = score[1]+score[2]+score[3];
		for(int j = 0; j < 4; j++)	//4个map循环；
		{
			if(mp[j].count(score[j]))	//已经存在，直接插入
				mp[j][score[j]].push_back(id);
			else
			{
				vector<int> v;
				v.push_back(id);
				mp[j].insert(make_pair(score[j], v));
			}
		}
	}

	map<int, Node> result;	//保存结果的map；
	int cnt = 1;
	map<int, vector<int>, greater<int> >::iterator it;	//对map迭代；
	for(i = 0; i < 4; i++)	//对4个map遍历，建立结果map；
	{
		cnt = 1;	//表示排名；
		for(it = mp[i].begin(); it != mp[i].end(); it++)
		{
			for(unsigned j = 0; j < it->second.size(); j++)
			{
				id = it->second[j];
				result[id].rank[i] = cnt;	//相同排名；
			}
			cnt += it->second.size();	//此处不是加1，原因参见思路；
		}
	}

	char ch[4] = {'A', 'C', 'M', 'E'};
	for(i = 0; i < M; i++)	//输出；
	{
		cin >>id;
		if(result.count(id))	//id存在；
		{
			int min = result[id].rank[0];
			int min_pos = 0;
			for(int j = 1; j < 4; j++)	//找出最佳排名；
			{
				if(result[id].rank[j] < min)
				{
					min = result[id].rank[j];
					min_pos = j;
				}
			}
			cout << min << ' ' << ch[min_pos] << endl;
		}
		else
			cout << "N/A" << endl;	//id不存在；
	}

	return 0;
}

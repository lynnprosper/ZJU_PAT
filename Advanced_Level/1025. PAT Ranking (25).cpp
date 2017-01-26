#include<iostream>
#include<vector>
#include<algorithm> //使用sort()
#include<string>
using namespace std;

struct stu	//学生的结构体
{
	bool operator<(const stu &b) const	//重载比较运算符
	{
		if(score != b.score)
			return score > b.score;
		else
			return id < b.id;
	}
	string id;	//存储id
	int score;
	int location;
	int local_rank;
	int total_rank;	//存储总排名
};

/*
题意：
对考生成绩进行局部和整体排名。
思路：
每个考生结构体进行排序就可以了。
排序函数可以单独写，为了简便，写在结构体里面（重载）。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int N, K;
	vector<stu> person;
	int amount = 0;	//总人数
	cin >> N;
	vector<stu>::iterator it;//vector的迭代器
	for(int i = 1; i <= N; i++)
	{
		cin >> K;
		amount += K;
		for(int j = 0; j < K; j++)	//读入数据
		{
			stu student;
			cin >> student.id >> student.score;
			student.location = i;
			person.push_back(student);
		}

		it = person.end() - K;
		sort(it, person.end());	//排序
		int cur_rank = 1;
		int cnt = 0;
		int last_score = -1;

		for(it; it != person.end(); it++)	//局部排名
		{
			cnt++;
			if(it->score != last_score)
			{
				it->local_rank = cnt;
				cur_rank = cnt;
				last_score = it->score;
			}
			else
			{
				it->local_rank = cur_rank;
			}
		}
	}

	sort(person.begin(), person.end());
	int cur_rank = 1;
	int cnt = 0;
	int last_score = -1;

	for(it = person.begin(); it != person.end(); it++)//整体排名
	{
		cnt++;
		if(it->score != last_score)
		{
			it->total_rank = cnt;
			cur_rank = cnt;
			last_score = it->score;
		}
		else
		{
			it->total_rank = cur_rank;
		}
	}

	cout << amount << endl;	//输出结果
	for(it = person.begin(); it != person.end(); it++)
	{
		cout << it->id << " "
			<< it->total_rank << " "
			<< it->location << " "
			<< it->local_rank << endl;
	}

	return 0;
}

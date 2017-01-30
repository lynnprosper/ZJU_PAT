#include<iostream>
#include<string>
using namespace std;

struct Node //学生结构体
{
	Node(): score(-1) {}
	string name, id;
	int score;
};

//思路：基础数据处理题，读入数据时处理就可以了。
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N;
	cin >> N;
	Node male, female;//存储最低分数的男性和最高分数女性的信息
	male.score = 101;

	for (int i = 0; i < N; i++)
	{
		string sn, sid;
		char gen;
		int gra;
		cin >> sn >> gen >> sid >> gra;

		if(gen == 'F')//女性
		{
			if(gra > female.score)
			{
				female.id = sid;
				female.name = sn;
				female.score = gra;
			}
		}
		else//男性
		{
			if(gra < male.score)
			{
				male.id = sid;
				male.name = sn;
				male.score = gra;
			}
		}
	}

	if (female.score > -1)//输出
		cout << female.name << ' ' << female.id << endl;
	else
		cout << "Absent\n";

	if (male.score < 101)
		cout << male.name << ' ' << male.id << endl;
	else
		cout << "Absent\n";

	if (female.score > -1 && male.score < 101)
		cout << female.score-male.score << endl;
	else
		cout << "NA" << endl;

	return 0;
}

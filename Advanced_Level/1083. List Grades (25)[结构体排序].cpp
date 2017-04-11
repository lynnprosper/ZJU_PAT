#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Student	//定义结构体
{
	bool operator< (const Student &b)//运算符重载，降序
	{
		if (m_grade > b.m_grade)
			return true;
		else
			return false;
	}
	int m_grade;
	string m_name;
	string m_id;
};

/*
题意：结构体排序。
思路：
有多种方法。我用的vector排序，因为每个成绩是唯一的。
排好序，遍历输出。
已AC.
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N;//总数
	cin >> N;
	vector<Student> stu(N);

	for (int i = 0; i < N; i++)//读入数据
	{
		cin >> stu[i].m_name >> stu[i].m_id >> stu[i].m_grade;
	}
	sort(&stu[0], &stu[0]+N);

	int leftInterval, rightInterval;
	cin >> leftInterval >> rightInterval;

	int flag = 0;
	for (int i = 0; i < N; i++)//遍历输出
	{
		if (stu[i].m_grade > rightInterval)
			continue;
		else if (stu[i].m_grade >= leftInterval)
		{
			cout << stu[i].m_name << ' ' << stu[i].m_id << endl;
			flag = 1;
		}
		else
			break;
	}

	if (flag == 0)
		cout << "NONE" << endl;

	return 0;
}

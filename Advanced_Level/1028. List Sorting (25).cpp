#include<iostream>
#include<algorithm>	//使用sort函数
#include<cstring>	//使用strcmp函数
using namespace std;

struct Stu
{
	bool operator<(const Stu &b) const	//重载比较运算符，也可以单独写个比较函数
	{
		return id < b.id;
	}
	int id;
	char name[9];
	int score;
};

bool Cmp2(const Stu &a, const Stu &b);	//按名字字典序排序
bool Cmp3(const Stu &a, const Stu &b);	//按分数排序

//思路：排序问题。注意不要用string表示名字，会超时
//同时I/O用printf和scanf。
int main()
{
	freopen("in.txt", "r", stdin);
	int N, C;
	scanf("%d %d", &N, &C);
	Stu *student = new Stu[N];

	for (int i = 0; i < N; i++)
		scanf("%d %s %d", &student[i].id, &student[i].name, &student[i].score);

	switch(C)
	{
	case 1:
		sort(student, student+N);
		break;
	case 2:
		sort(student, student+N, Cmp2);
		break;
	default:
		sort(student, student+N, Cmp3);
		break;
	}

	for (int i = 0; i < N; i++)
		printf("%06d %s %d\n", student[i].id, student[i].name, student[i].score);

	delete[] student;
	return 0;
}

bool Cmp2(const Stu &a, const Stu &b)//按名字字典序排序
{
	if (strcmp(a.name, b.name) == 0)
		return a.id < b.id;
	else
		return strcmp(a.name, b.name) < 0;
}

bool Cmp3(const Stu &a, const Stu &b)//按分数排序
{
	if (a.score == b.score)
		return a.id < b.id;
	else
		return a.score < b.score;
}

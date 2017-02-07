#include<iostream>
#include<algorithm>//使用sort函数
#include<cstring>//使用strcmp函数
using namespace std;

struct Node//每个人的结构体
{
	bool operator<(const Node &b) const//重载比较运算符
	{
		if (wea != b.wea)
			return wea > b.wea;
		else if (age != b.age)
			return age < b.age;
		else
			return strcmp(name, b.name) < 0;
	}
	char name[10];//存储名字
	int age, wea;//分别为年龄， 财富
};

/*
题意：
根据给定的年龄范围输出财富排行榜。
思路：
数据处理题。不难，建结构体，按照要求排序。
然后对符合范围的遍历输出。
注意：尽量不要用string，会超时。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N, K;
	scanf("%d %d", &N, &K);
	Node *pe = new Node[N];//存储每个人的信息

	for (int i = 0; i < N; i++)
		scanf("%s %d %d", &pe[i].name, &pe[i].age, &pe[i].wea);
	sort(pe, pe+N);//根据给定要求排序

	for (int i = 0; i < K; i++)
	{
		printf("Case #%d:\n", i + 1);
		int M, amin, amax;
		scanf("%d %d %d", &M, &amin, &amax);
		
		int cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (pe[j].age >= amin && pe[j].age <= amax)//符合范围的输出
			{
				cnt++;
				printf("%s %d %d\n", pe[j].name, pe[j].age, pe[j].wea);
			}
			if (cnt == M)
				break;
		}

		if (cnt == 0)
			printf("None\n");
	}

	delete[] pe;
	return 0;
}

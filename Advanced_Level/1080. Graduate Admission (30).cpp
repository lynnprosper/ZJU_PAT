#include<iostream>
#include<algorithm>//使用sort函数
#include<vector>
using namespace std;

struct Node
{
	bool operator<(const Node &b) const//重载比较运算符
	{
		if (sum != b.sum)
			return sum > b.sum;
		else
			return ge > b.ge;
	}
	int id, ge, gi, sum;//分别为学生编号， 入学分数，面试分数，总分
};
const int Max = 40000 + 5;//最大学生数目
int wish[Max][6];//学生志愿表

/*
题意：结构体排序。
按照总分->入学分数排序。
刚开始想复杂了，以为学校先录取第一志愿的。其实不管几志愿，一视同仁，从高分开始录。
所以，根据学生分数排名，从第一个学生去判断他的志愿学校能否录取就可以了，不需要考虑其他的。
思路：
关键之处是当多个排名一致时，无论是否超额，都录取。
已AC
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	vector<int> quota(M);//学校录取名额
	vector< vector<int> > result(M);//学校录取结果
	vector<Node> stu(N);//每个学生信息

	for (int i = 0; i < M; i++)//读入数据
		scanf("%d", &quota[i]);
	for (int i = 0; i < N; i++)
	{
		stu[i].id = i;
		scanf("%d %d", &stu[i].ge, &stu[i].gi);
		stu[i].sum = stu[i].ge + stu[i].gi;

		for (int j = 0; j < K; j++)
			scanf("%d", &wish[i][j]);
	}
	vector<Node> origin = stu;//保存原始信息
	sort(stu.begin(), stu.end());//降序排序

	for (int i = 0; i < N; i++)//判断并录取
	{
		for (int j = 0; j < K; j++)
		{
			int wishschool = wish[stu[i].id][j];//志愿学校
			if (quota[wishschool] > 0)//还有名额
			{
				result[wishschool].push_back(stu[i].id);
				quota[wishschool]--;
				break;
			}
			else//无名额，看该学生是否和最后录取的分数都一致，是则录取
			{
				int last = *result[wishschool].rbegin();
				if (stu[i].sum == origin[last].sum && stu[i].ge == origin[last].ge)
				{
					result[wishschool].push_back(stu[i].id);
					break;
				}
			}
		}
	}

	for (int i = 0; i < M; i++)//输出
	{
		if (!result[i].empty())
		{
			sort(result[i].begin(), result[i].end());
			for (int j = 0; j < result[i].size(); j++)
			{
				if (j == 0)
					printf("%d", result[i][j]);
				else
					printf(" %d", result[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}

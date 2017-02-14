#include<iostream>
#include<algorithm>//使用sort函数
#include<vector>
using namespace std;

int sc[6] = { -1, -1, -1, -1, -1, -1 };//得分初始化-1
struct Node
{
	bool operator<(const Node &b) const//重载比较运算符
	{
		if (total != b.total)
			return total > b.total;
		else
		{
			if (perfect_id != b.perfect_id)
				return perfect_id > b.perfect_id;
			else
				return id < b.id;
		}
	}

	Node() : total(0), perfect_id(0), flag(0), score(sc, sc+6) {}//初始化
	int id, total, perfect_id;//分别为编号， 总分， 满分的题目数
	int flag;//标记是否统计该学生分数
	vector<int> score;//存储每道题分数，初始化为-1
};

/*
题意：分数排名问题。
排序方式：总分（降序）->满分的题目数（降序）->编号（升序）
要点：
1. 无法通过编译的得分是0.
2. 从未提交或无法通过编译的不统计。
3. 得分0的也要统计排名。
思路：
结构体排序。
为了方便统计，得分分数初始化为-1.这样输出时，-1则输出‘-’。   已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N, K, M, fscore[6];//分别为人数， 题目数， 提交数， 题目的满分
	scanf("%d %d %d", &N, &K, &M);
	for (int i = 1; i <= K; i++)
		scanf("%d", &fscore[i]);

	vector<Node> stu(N + 1);//存储每个人的信息, 为便于处理，下标从1开始
	for (int i = 0; i < M; i++)//读入数据
	{
		int t_id, t_num, t_score;//分别为读入的id， 题目号， 分数
		scanf("%d %d %d", &t_id, &t_num, &t_score);
		stu[t_id].id = t_id;
		if (stu[t_id].score[t_num] == -1)//说明有提交，则先把该题目分数置为0
			stu[t_id].score[t_num] = 0;

		if (t_score > -1)
			stu[t_id].flag = 1;//标记要统计
		if (t_score > stu[t_id].score[t_num])//更新信息
		{
			if (t_score == fscore[t_num])
				stu[t_id].perfect_id++;
			stu[t_id].total += (t_score - stu[t_id].score[t_num]);
			stu[t_id].score[t_num] = t_score;
		}
	}

	sort(stu.begin(), stu.end());//排序
	int rank, cur_rank;//分别为总排名， 当前排名
	rank = cur_rank = 0;
	int last_score = -1;//上一个人的总分

	for (int i = 0; i <= N; i++)//输出
	{
		if (stu[i].flag == 0)//不统计
			continue;
		rank++;

		if (stu[i].total != last_score)//不等于上一个人的总分
		{
			cur_rank = rank;
			last_score = stu[i].total;
		}
		
		printf("%d %05d %d", cur_rank, stu[i].id, stu[i].total);
		for (int j = 1; j <= K; j++)
		{
			if (stu[i].score[j] > -1)
				printf(" %d", stu[i].score[j]);
			else
				printf(" -");
		}
		printf("\n");
	}

	return 0;
}

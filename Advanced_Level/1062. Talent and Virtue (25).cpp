#include<iostream>
#include<algorithm>//使用sort函数
#include<vector>
using namespace std;

struct Node//分数结构体
{
	Node(int d, int v, int t) : id(d), sg(v + t), vg(v), tg(t) {}//初始化
	bool operator<(const Node &b) const//重载比较运算符
	{
		if (sg != b.sg)
			return sg > b.sg;
		else
		{
			if (vg != b.vg)
				return vg > b.vg;
			else
				return id < b.id;
		}
	}
	int id;
	int sg, vg, tg;//分别为总分，美德分数， 才能分数
};

/*
题意：
结构体的内部排序。
思路：
排序题。由于是4个部分，所以用了4个vector。
注意不要用cin，超时。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N, low, high;
	scanf("%d %d %d", &N, &low, &high);
	vector<Node> vec[4];
	Node t(1, 2, 3);

	int valid = 0;//有效人数
	for (int i = 0; i < N; i++)
	{
		int id, v, t;
		scanf("%d %d %d", &id, &v, &t);
		Node tem(id, v, t);

		if (v < low || t < low)//无效，读下一组数据
			continue;

		if (v >= high && t >= high)//放入合适的vector。
			vec[0].push_back(tem);
		else if (t < high && v >= high)
			vec[1].push_back(tem);
		else if (v >= t)
			vec[2].push_back(tem);
		else
			vec[3].push_back(tem);
		valid++;
	}

	for (int i = 0; i < 4; i++)
		sort(vec[i].begin(), vec[i].end());

	printf("%d\n", valid);//输出
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
			printf("%d %d %d\n", vec[i][j].id, vec[i][j].vg, vec[i][j].tg);
	}

	return 0;
}

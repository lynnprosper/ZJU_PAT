#include<iostream>
#include<algorithm>//使用sort函数
#include<vector>
using namespace std;

struct Node
{
	Node() : id(-1), parent(-1), sets(0), area(0) {}//父结点初始化为-1，表示自己就是根
	bool operator<(const Node &b) const//重载比较运算符，先安装父结点值升序，再按照id降序。所以id初始为-1
	{
		if (parent != b.parent)
			return parent < b.parent;
		else
			return id > b.id;
	}
	int id, parent, sets, area;//分别为结点号， 父结点号， 该人的套数， 面积
	double avg_area, avg_sets;//平均面积及套数
};
const int Max = 10000;//结点数最大值
Node s[Max];//下标映射结点号

int find(int x);//并查集的查找根结点函数
void Union(int root1, int root2);//并查集的合并
bool cmp(const Node &a, const Node &b);//最后输出的排序

/*
题意：
找出同一个有关系的家庭里的人数，房产套数及总面积。
思路：
并查集或者dfs算法。
集合问题，并查集优先。

我是先把结点进行合并，
合并好后按照根结点值升序（因为s[i].parent是负值，绝对值是该集合的人数),同时累计该集合的套数及面积。
最后排序输出就好了。
注意：
合并的时候要把编号大的合并到小的那里去。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	
	vector<Node> data(N);//存储现有结点数
	for (int i = 0; i < N; i++)
	{
		vector<int> tnode;//存储每个id下有关系的人
		int t_id, f, m, k;//分别为当前编号， 父亲编号，目前编号， 孩子数
		scanf("%d %d %d %d", &t_id, &f, &m, &k);
		tnode.push_back(f);//插入数组
		tnode.push_back(m);
		for (int j = 0; j < k; j++)
		{
			int child;
			scanf("%d", &child);
			tnode.push_back(child);
		}
		data[i].id = t_id;
		s[t_id].id = t_id;
		scanf("%d %d", &data[i].sets, &data[i].area);

		for (int j = 0; j < tnode.size(); j++)//对数组统一处理
		{
			if (tnode[j] != -1)
			{
				s[tnode[j]].id = tnode[j];
				int root1 = find(t_id);
				int root2 = find(tnode[j]);
				Union(root1, root2);//合并
			}
		}
	}
	
	for (int i = 0; i < N; i++)//累计套数和面积
	{
		s[find(data[i].id)].area += data[i].area;
		s[find(data[i].id)].sets += data[i].sets;
	}
	sort(s, s + Max);//排序

	int cnt = 0;//集合数目
	vector<Node> re;//存储最终结果
	for (int i = 0; i < Max; i++)
	{
		if (s[i].parent < 0 && s[i].id > -1)//计算有效的根结点
		{
			s[i].avg_area = (double)s[i].area / (-s[i].parent);
			s[i].avg_sets = (double)s[i].sets / (-s[i].parent);
			re.push_back(s[i]);
			cnt++;
		}
		else
			break;
	}
	sort(re.begin(), re.end(), cmp);//对结果排序
	
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
	{
		printf("%04d %d %.3lf %.3lf\n", re[i].id, -re[i].parent, re[i].avg_sets,
			re[i].avg_area);
	}

	return 0;
}

int find(int x)//并查集的查找根结点函数
{
	if (s[x].parent < 0)
		return x;
	else
		return (s[x].parent = find(s[x].parent));//利用了路径压缩
}

void Union(int root1, int root2)//并查集的合并
{
	if (root1 < root2)//大的合并到小的
	{
		s[root1].parent += s[root2].parent;
		s[root2].parent = root1;
	}
	else if (root2 < root1)
	{
		s[root2].parent += s[root1].parent;
		s[root1].parent = root2;
	}
}

bool cmp(const Node &a, const Node &b)//最后输出的排序
{
	if (a.avg_area != b.avg_area)
		return a.avg_area > b.avg_area;
	else
		return a.id < b.id;
}

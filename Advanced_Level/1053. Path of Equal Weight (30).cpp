#include<iostream>
#include<algorithm>//使用sort函数
#include<vector>
using namespace std;

vector<int> pwt;//存储路径的每个结点权值
vector<int> nwt;//存储树的每个结点权值
int N, M, S;//分别为总结点数， 非叶子节点数，给出的权值
struct Node
{
	bool operator<(const Node &b) const//重载比较运算符
	{
		return wgt > b.wgt;
	}
	int id;//结点编号
	int wgt;//权值
};
vector< vector<Node> > vtree;//类似图的邻接表表示，嵌套vector，表示结点的孩子

void dfs(int s, int sum);//dfs，参数为遍历起点，累计的权值

/*
题意：
遍历出从根到叶子路径的总权值与给定的相等的序列。
思路：
核心是dfs了。
然后一个问题是序列从大到小输出？
怎么做呢。假设我们每次都从最大的孩子递归遍历，
那么结果正是我们要的。
所以，我们对每个父结点的孩子降序排序后，再dfs就好了。
已AC
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	cin >> N >> M >> S;
	nwt.resize(N);//重新定义数组大小
	vtree.resize(N);

	for (int i = 0; i < N; i++)//保存每个结点权值
		cin >> nwt[i];
	for (int i = 0; i < M; i++ )
	{
		int par, num;
		cin >> par >> num;
		vtree[par].resize(num);

		for (int j = 0; j < num; j++)//每个孩子结点压入父结点的数组中
		{
			Node tem;
			cin >> tem.id;
			tem.wgt = nwt[tem.id];
			vtree[par][j] = tem;
		}
		sort(vtree[par].begin(), vtree[par].end());//降序排序
	}
	
	dfs(0, 0);

	return 0;
}

void dfs(int s, int sum)
{
	sum += nwt[s];
	pwt.push_back(nwt[s]);

	if (sum > S)//大于直接返回上一级
		return;
	if (sum == S && vtree[s].empty())//相等且为叶子结点，为所求，输出结果
	{
		for (int i = 0; i < pwt.size(); i++)
		{
			if (i == 0)
				cout << pwt[i];
			else
				cout << ' ' << pwt[i];
		}
		cout << endl;
		return;
	}

	if (sum < S && vtree[s].size() > 0)//小于的话，继续dfs
	{
		for (int i = 0; i < vtree[s].size(); i++)
		{
			dfs(vtree[s][i].id, sum);
			pwt.pop_back();//从dfs里返回后要弹出最后压入的
		}
	}

	return;
}

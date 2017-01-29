#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

const int M = 26*26*26;	//结点最大数目
vector<int> v[M];	//图的邻接表表示
vector<int> node;	//存储遍历的起点
int visited[M] = {0};
int w[M] = {0};	//存储每个人的通话时长
int n, k;	//k是阈值
int cnt = 0;//达标的帮派数目
int pnum;	//一个帮派的成员数
int maxtime;//成员中的最大通话时长
int headtime;//头目通话时长
int headId;//头目id

int toId(string &s);//字符串名字转换为数字编号
string toName(int x);//编号转换为名字，用于输出
void dfs(int start);//dfs算法

/*
题意：
给你很多条边，求出符合条件的连通分量数，以及每个
连通分量中的成员数。
思路：
由于给出的结点不是数字编号且不连续，需要进行转换。
这里，把三个字符看做26进制，模拟图的构造，稀疏边，用邻接表。
求连通分量可以用dfs，或者并查集。
这里用的dfs，同时dfs时收集成员数以及头目。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> n >> k;

	for (int i = 0; i < n; i++)//读入数据，同时转换成数字编号
	{
		string s1, s2;
		int wgt;
		cin >> s1 >> s2 >> wgt;
	
		int d1 = toId(s1);
		int d2 = toId(s2);
		v[d1].push_back(d2);
		v[d2].push_back(d1);
		w[d1] += wgt;
		w[d2] += wgt;
		node.push_back(d1);//稀疏边，存储遍历的起点。这样不需要从0一个个遍历了
	}
	
	map<string, int> h_map;//利用map的有序性，存储头目信息
	vector<int>::iterator it;
	for (it = node.begin(); it < node.end(); it++)
	{
		pnum = 0;
		maxtime = 0;
		headtime = 0;
		if (visited[*it] == 0)
			dfs(*it);
		
		if ( pnum > 2 && maxtime > 2*k)//判断是否符合条件的帮派
		{
			cnt++;
			string name = toName(headId);
			h_map[name] = pnum;
		}
	}

	cout << cnt << endl;//输出
	if ( cnt != 0)
	{
		map<string, int>::iterator it;
		for (it = h_map.begin(); it != h_map.end(); it++)
			cout << it->first << ' ' << it->second << endl;
	}
	
	return 0;
}

int toId(string &s)//字符串名字转换为数字编号
{
	return ((s[0]-'A')*26*26 + (s[1]-'A')*26 + (s[2]-'A'));
}

string toName(int x)//编号转换为名字，用于输出
{
	string s(3, 0);
	s[2] = x%26 + 'A';
	s[1] = x/26%26 + 'A';
	s[0] = x/26/26 + 'A';

	return s;
}

void dfs(int start)//dfs算法, 里面用到的变量为便于遍历，都设为全局变量
{
	visited[start] = 1;
	pnum++;
	maxtime += w[start];
	if(w[start] > headtime)//更新头目信息
	{
		headtime = w[start];
		headId = start;
	}

	for (unsigned i = 0; i < v[start].size(); i++)//dfs遍历邻接点
	{
		if(visited[v[start][i]] == 0)
			dfs(v[start][i]);
	}

	return;
}

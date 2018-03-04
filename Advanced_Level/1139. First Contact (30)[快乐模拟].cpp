#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct Node
{
	bool operator< (const Node &b)
	{
		if (x == b.x)
			return (y < b.y);
		else
			return (x < b.x);
	}
	Node(){}
	Node(int a, int b) :x(a), y(b){}
	int x, y;
};

int N, M, K, ta, tb;
const int Max = 10000;
vector<int> G[Max];
bool H[Max][Max];

void process(int x, int y);


/*
题意：快乐模拟类。
给出A， B，找出A的同性朋友C和B的同性朋友D。
其中C和D认识，输出C，D。
思路：
读入数据时，用邻接表记录A的同性朋友。
同时，标记两个人联系为true。
查询时，两次循环即可。
注意：
1）id可能为-0000，读入数据按字符串处理。
2）C和D不能同一人。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	int x, y;
	char sa[10], sb[10];
	for (int i = 0; i < M; i++)
	{
		scanf("%s %s", sa, sb);
		x = abs(atoi(sa));
		y = abs(atoi(sb));
		if (sa[0] == '-' && sb[0] == '-')
		{
			G[x].push_back(y);
			G[y].push_back(x);
		}
		else if (sa[0] != '-' && sb[0] != '-')
		{
			G[x].push_back(y);
			G[y].push_back(x);
		}

		H[x][y] = H[y][x] = true;
	}

	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		scanf("%s %s", sa, sb);
		x = abs(atoi(sa));
		y = abs(atoi(sb));

		process(x, y);
	}

	return 0;
}

void process(int x, int y)
{
	if (G[x].size() < 1 || G[y].size() < 1)
	{
		printf("0\n");
		return;
	}

	vector<Node> re;
	for (int i = 0; i < G[x].size(); i++)
	{
		int c = G[x][i], d;
		for (int j = 0; j < G[y].size(); j++)
		{
			d = G[y][j];
			if (c == y || d == x) //排除同一个人的情况
				continue;
			if (H[c][d])
			{
				re.push_back(Node(c, d) );
			}
		}
	}

	sort(re.begin(), re.end());
	printf("%d\n", re.size());
	for (int i = 0; i < re.size(); i++)
	{
		printf("%04d %04d\n", re[i].x, re[i].y);
	}
}

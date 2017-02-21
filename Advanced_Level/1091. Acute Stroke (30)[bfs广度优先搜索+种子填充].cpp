#include<iostream>
#include<queue>
using namespace std;

int G[1286][128][60] = { 0 };//矩阵的三维表示。分别为行， 列及层次
int M, N, L, T;//分别为行数， 列数， 层数及阈值。
int cnt = 0;//累计符合要求的结点
int direct_x[6] = { -1, 1, 0, 0, 0, 0 };//x方向的偏移，下同
int direct_y[6] = { 0, 0, -1, 1, 0, 0 };
int direct_z[6] = { 0, 0, 0, 0, -1, 1 };
struct Node
{
	Node(int a, int b, int c) : x(a), y(b), z(c) {}
	int x, y, z;//用数组的下标表示结点的坐标
};

void bfs(int a, int b, int c);//bfs广度优先

/*
题意：
连通块问题，也称作种子填充问题，比较经典。
哎，题意挺费解的。给的图片也没有叙述清楚。
其实就是一个三维数组，即M行N列L层。
然后求出每个连通块的结点数大于等于阈值的总数目。即矩阵中1的数量。
图片里的蓝色代表当前结点，然后它的上下左右前后六个方向属于同一个连通块。
给个图片不给说明，真是蛋疼。
思路：
理顺题意，就简单啦。
dfs或者bfs判断连通体就行了，只不过这里是三维的。
然而这里用dfs行不通，最后两个测试点无法通过，因为栈深太大，OJ的机器爆栈，真是郁闷。
用dfs是最简单的。
摊手，只有用bfs了。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d %d %d", &M, &N, &L, &T);//分别为行， 列, 层和阈值
	for (int k = 0; k < L; k++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
				scanf("%d", &G[i][j][k]);//注意这里的顺序，可理解为x,y, z坐标
		}
	}

	for (int k = 0; k < L; k++)//因为不是强连通图，还需要加循环，进行bfs
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (G[i][j][k] == 1)
					bfs(i, j, k);
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}

void bfs(int a, int b, int c)
{
	queue<Node> Q;
	Q.push(Node(a, b, c));//入队
	int cur_cnt = 1;
	G[a][b][c] = 0;//标记该点已遍历

	while (!Q.empty())
	{
		Node tem = Q.front();
		Q.pop();
		G[tem.x][tem.y][tem.z] = 0;		

		for (int i = 0; i < 6; i++)//此处的6个方向可以用if判断，不过数组简单些
		{
			int newc = tem.z + direct_z[i];
			int newa = tem.x + direct_x[i];
			int newb = tem.y + direct_y[i];

			if ((newa < 0 || newa >= M) || (newb < 0 || newb >= N)//已出界
				|| (newc < 0 || newc >= L))
				continue;
			if (G[newa][newb][newc] == 0)//已访问或无效点
				continue;

			cur_cnt++;//访问新的结点
			G[newa][newb][newc] = 0;
			Q.push(Node(newa, newb, newc));
		}
	}

	if (cur_cnt >= T)
		cnt += cur_cnt;//累计

	return;
}

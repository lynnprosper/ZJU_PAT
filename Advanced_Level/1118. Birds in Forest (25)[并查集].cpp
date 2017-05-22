#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 10000 + 5;//鸟儿的最大数量
int s[MaxN];//并查集合

void Union(int root1, int root2);//合并两个并查集
int FindRoot(int x);//找出某只鸟所属集合的根

/*
题意：考察并查集。每张图片里的鸟儿都在一棵树上，判断有几棵树。
思路：
首先要对并查集熟悉。一个参考：http://dongxicheng.org/structure/union-find-set/
其实并查集就两个函数，一个合并，一个寻根。
了解并查集，这题就简单了。
每个图片的鸟儿进行合并就行了。
其中鸟儿的最大编号就是鸟儿的数量（题意是从1连续编号的）。
求有几棵树，对s数组遍历，小于0的有几个，就有几棵树。
最后对查询的判断根是否一致就行了。
已AC。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	for (int i = 0; i < MaxN; i++)//先对集合初始，此时每个id都是根，值用-1表示。
		s[i] = -1;//值的绝对值表示集合元素个数
	int N, maxId;
	maxId = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int num, b1, b2;
		scanf("%d %d", &num, &b1);
		maxId = max(b1, maxId);
		
		for (int j = 1; j < num; j++)
		{
			scanf("%d", &b2);
			maxId = max(b2, maxId);
			int root2 = FindRoot(b2);
			int root1 = FindRoot(b1);

			Union(root1, root2);//进行合并
		}
	}

	int treeNum = 0;
	for (int i = 1; i <= maxId; i++)
	{
		if (s[i] < 0)
			treeNum++;//累计树的数量
	}
	printf("%d %d\n", treeNum, maxId);

	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		int b1, b2;
		scanf("%d %d", &b1, &b2);
		if (FindRoot(b1) == FindRoot(b2))//相等，在一棵树上
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}

void Union(int root1, int root2)//合并两个并查集
{
	if (s[root1] > s[root2])//小集合并入大集合，按秩归并思想
	{
		s[root2] += s[root1];
		s[root1] = root2;
	}
	else
	{
		s[root1] += s[root2];
		s[root2] = root1;
	}
	
	return;
}
int FindRoot(int x)//找出某只鸟所属集合的根
{
	if (s[x] < 0)
		return x;
	else
		return(s[x] = FindRoot(s[x]));//这里用到了路径压缩，为了找根方便
}

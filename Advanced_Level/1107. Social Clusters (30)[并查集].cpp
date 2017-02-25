#include<iostream>
#include<vector>
#include<algorithm>//使用sort函数
using namespace std;

int N;//总人数
vector<int> s;//存储圈子的情况，s[i]表示编号i的人的父结点号。
vector<int> hobby(1001, 0);//下标为兴趣编号，值表示拥有该兴趣的人的编号。

void Union(int root1, int root2);//并查集的合并两个集合, 参数是两个集合的根（某人的编号）。
int FindRoot(int x);//并查集的查找集合的根, 参数是人的编号

/*
题意：
根据共同的兴趣找出共有几个圈子。
思路：
并查集问题。
根据题意，很容易知道是关于集合的问题。对于集合问题，并查集是最简单的。
当然可以用bfs，但是没有并查集算法简捷。

并查集其实就两个函数，一个合并，一个查找根。
两个数组s和hobby。
初始时s[i]= -1， 表示每个人都是根。（根时，值的绝对值表示该集合人数）。
对于爱好，初始时，hobby[i] = 0，即无人有该爱好。
读入数据，对于k号的j个爱好，若该爱好i无人，那么hobby[i] = k,即k号有爱好i。
若该爱好i已经有人了（hobby[i] != 0), 那么说明这两个人可以是一个圈子，进行合并就好了。
所以，当读完数据时，集合也合并好了。

此时，我们要知道每个集合的根值是负值，非负则不是根。
那么我们升序排序，越小说明圈子人越多。
最后输出负值的圈子。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	scanf("%d", &N);
	s.resize(N + 1, 0);//编号从1起
	for (int i = 1; i <= N; i++)//读入数据并进行处理合并
	{
		s[i] = -1;//并查集的初始化

		int num;//每个人的爱好数
		scanf("%d: ", &num);
		for (int j = 0; j < num; j++)
		{
			int type;//爱好编号
			scanf("%d", &type);
			if (hobby[type] == 0)//第一次有人有该爱好，相当于该人可以作为集合的跟了，后面人都指向他。
				hobby[type] = i;
			else
			{
				int r1 = FindRoot(i);//找到i这个人的根
				int r2 = FindRoot(hobby[type]);//找到有这个爱好的人所在圈子的根
				Union(r1, r2);//合并两个圈子
			}
		}
	}
	
	sort(s.begin(), s.end());//升序
	int cnt = 0;//记录圈子数
	for (int i = 0; i < s.size() && s[i] < 0; i++)
		cnt++;
	printf("%d\n", cnt);

	for (int i = 0; i < cnt; i++)
	{
		if (i != 0)
			printf(" ");
		printf("%d", -s[i]);
	}
	printf("\n");

	return 0;
}

void Union(int root1, int root2)//并查集的合并两个集合, 参数是两个集合的根（某人的编号）。
{
	if (root1 < root2)//这里进行了优化，即按秩归并（把小集合并到大集合里，可以减少树深度）。
	{
		s[root1] += s[root2];//更新合并后的集合人数
		s[root2] = root1;		//小集合根指向新集合的根
	}
	else
	{
		s[root2] += s[root1];
		s[root1] = root2;
	}
}

int FindRoot(int x)//并查集的查找集合的根, 参数是人的编号
{
	if (s[x] < 0)//小于0，找到了根
		return x;
	else//递归查找，这里也进行了优化。即路径压缩，把该圈子所有人都指向根，减少树深度。
		return s[x] = FindRoot(s[x]);
}

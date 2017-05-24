#include <iostream>
#include <map>
using namespace std;

/*
题意：给出一组伴侣，以及参加聚会的人的编号。判断哪些参加聚会的人是单人来的。
思路：
数学逻辑题。
有多种方法，可以用数组。
此题主要是映射问题，为了简便，我用的map。
把伴侣的id记录在一个map里。a到b，b到a需要同时记录，为了后面查询。
然后把参加的id记录在另一个map里。插入的时候需判断他的伴侣是否已经来了。
没有的话插入map，有的话不能插入， 而是记录在伴侣那里。
最后map里少的个数就是已经配对的组数。
而map里每个元素的第二个对象是-1（初始值）时就是单身，输出即可。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N, K;
	map<int, int> pair, attendance;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		pair[a] = b;//两者互相映射
		pair[b] = a;
	}

	scanf("%d", &K);
	for (int i = 0; i < K; i++)//处理参加聚会的
	{
		int a;
		scanf("%d", &a);
		if (attendance.count(pair[a]) != 0)//说明伴侣已经来了
			attendance[pair[a]] = a;
		else
			attendance[a] = -1;
	}

	int mapSize = attendance.size();
	int single = 2 * mapSize - K;
	printf("%d\n", single);//单的人数

	int flag = 0;//为了输出空格的情况
	map<int, int>::iterator iter = attendance.begin();
	for (iter; iter != attendance.end(); iter++)
	{
		if (iter->second == -1)//-1即为单的
		{
			if (flag != 0)
				printf(" ");
			printf("%05d", iter->first);
			flag = 1;
		}
	}

	return 0;
}

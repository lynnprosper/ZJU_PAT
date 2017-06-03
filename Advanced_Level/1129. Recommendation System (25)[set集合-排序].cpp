#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct Node//存储物品信息的结构体
{
	Node(int a, int b) : sin(a), cnt(b) {}//构造函数
	bool operator< (const Node &b) const//比较运算符重载，const不能少
	{
		if (cnt == b.cnt)
		{
			return sin < b.sin;
		}
		else
			return cnt > b.cnt;
	}
	int sin;//物品编号
	int cnt;//出现的次数
};

/*
题意：给出用户查询过的编号，输出用户查询过的最多次数的前K个。
思路：
结构体排序题。
不过这次要用集合比较好。
set有自动排序功能。所以我们按照题意对set的比较运算符重载，让set自动排序。
用户的每一次查询，我们就直接输出set的前k个就行了。
然后，判断此次查询的编号是否在set里。在的话，先删除，次数+1，再重新插入。
已AC。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int N, K, id;
	scanf("%d %d", &N, &K);
	set<Node> item;//存储物品信息的集合
	int amount[50000 + 5] = { 0 };//存储某物品已出现过的次数
	scanf("%d", &id);
	item.insert(Node(id, 1));//先插入第一个，因为不需要输出
	amount[id]++;

	for (int i = 1; i < N; i++)
	{
		scanf("%d", &id);

		printf("%d:", id);
		int showNum = 0;
		for (auto iter = item.begin(); iter != item.end() && showNum < K; iter++, showNum++)
		{
			printf(" %d", iter->sin);//输出偏好，auto是自动变量类型，c++11的新特性
		}
		printf("\n");

		auto iter = item.find(Node(id, amount[id]));
		amount[id]++;
		if (iter != item.end())//删除原来的
		{
			item.erase(iter);
		}
		item.insert(Node(id, amount[id]));//重新插入
	}

	return 0;
}

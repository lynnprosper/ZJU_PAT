#include<iostream>
#include<algorithm>//使用reverse函数
#include<vector>
#include<map>
using namespace std;

struct Node
{
	Node() {}//默认构造函数
	Node(int a, int d, int n) : add(a), data(d), next(n) {}//构造函数
	int add, data, next;//分别为所在地址， 数据， 下一个地址
};

/*
题意：将链表的一部分分别逆序。
思路：
链表题。
首先要构建出正确的链表，题目给出的结点有可能不属于链表。
然后对链表的子链表逆序。
有多种方法，可以用数组下标模拟地址。
我是用map记录的结点。构建链表时把结点压入vector里，
逆序使用了stl里的reverse函数。然后输出就好了。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int head, N, K;//分别为首地址，总结点数， 子链表结点数
	scanf("%d %d %d", &head, &N, &K);
	map<int, Node> ap;//存储所有结点

	for (int i = 0; i < N; i++)//读入数据
	{
		int local, value, next_a;
		scanf("%d %d %d", &local, &value, &next_a);
		Node tem(local, value, next_a);
		ap.insert(make_pair(local, tem));
	}

	vector<Node> list;//有效链表
	int cur_add = head;
	int cnt = 0;
	while (cur_add != -1)//-1表示已到末尾
	{
		list.push_back(ap[cur_add]);
		cur_add = ap[cur_add].next;
		cnt++;
	}

	vector<Node>::iterator it = list.begin();
	for (int i = K; i <= cnt; i += K)
		reverse(it + i - K, it + i);//逆序子链表

	for (int i = 0; i < list.size(); i++)//输出
	{
		if (i == list.size() - 1)
			printf("%05d %d -1\n", list[i].add, list[i].data);
		else
			printf("%05d %d %05d\n", list[i].add, list[i].data, list[i + 1].add);
	}

	return 0;
}

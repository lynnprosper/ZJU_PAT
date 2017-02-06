#include<iostream>
#include<vector>
#include<algorithm>//使用sort函数
using namespace std;
const int MAX = 100000;

struct Node//结点结构体
{
	bool operator<(const Node &b) const//重载比较运算符
	{
		return key < b.key;
	}
	Node() : add(0) {}//初始化地址为0
	int add;//结点所在地址
	int key;
	int next;
};

/*
题意：
给出链表的静态表示方式，把链表从小到大排序。
思路：
先建一个MAX大的数组，下标表示地址，存储给出的结点。
然后从首地址开始遍历，压入数组list中。
最后输出。
注意：
1. 链表为空，输出“0 -1”。
2. 给出的结点可能不在链表上。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N, head;
	cin >> N >> head;
	vector<Node> nv(MAX);
	for (int i = 0; i < N; i++)//存储数据
	{
		Node tem;
		cin >> tem.add >> tem.key >> tem.next;
		nv[tem.add] = tem;
	}

	if (nv[head].add == 0)//表示链表空
	{
		printf("0 -1\n");
		return 0;
	}

	int pnext = head;
	vector<Node> list;//保存有效结点的数组
	while (pnext != -1)
	{
		list.push_back(nv[pnext]);
		pnext = nv[pnext].next;
	}

	sort(list.begin(), list.end());//升序排序
	int cnt = list.size();
	printf("%d %05d\n", cnt, list[0].add);
	for (int i = 0; i < cnt; i++)
	{
		if (i == cnt - 1)
			printf("%05d %d -1\n", list[i].add, list[i].key);
		else
			printf("%05d %d %05d\n", list[i].add, list[i].key, list[i + 1].add);
	}

	return 0;
}

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 1e4 +5;
struct Node	//结点的结构体
{
	int local;
	int data;
	int next;
};

void Print(vector<Node> &v);//输出链表

/*
题意：链表题
给出一个静态链表信息，去掉所有数据值（绝对值）重复的结点。
	最后输出挑选出的链表和废弃的被移除的结点组成的链表。
思路：
有多个方法，可以用数组。我这里用的stl里的map。
把读入的结点存入map中。
然后再从起点开始读，第一次出现的值的结点存入一个vector，重复的存入另一个。
最后分别输出即可。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int head, N;
	scanf("%d %d", &head, &N);

	map<int, Node> allData;//存储所有结点
	for (int i = 0; i < N; i++)
	{
		Node tem;
		scanf("%d %d %d", &tem.local, &tem.data, &tem.next);
		allData.insert(make_pair(tem.local, tem));
	}

	int curAddr = head;//当前地址
	vector<Node> select, abandon;//分别存储挑选好的和被移除的
	int flag[maxN] = { 0 };//某个值是否第一次出现的标记数组
	while (curAddr != -1)
	{
		int curData = abs(allData[curAddr].data);//取绝对值
		int nextAddr = allData[curAddr].next;
		if (flag[curData] == 0)//表示第一次出现
		{
			select.push_back(allData[curAddr]);
			flag[curData] = 1;
		}
		else
		{
			abandon.push_back(allData[curAddr]);
		}
		curAddr = nextAddr;
	}

	Print(select);
	Print(abandon);

	return 0;
}

void Print(vector<Node> &v)//输出链表
{
	int len = v.size();
	for (int i = 0; i < len; i++)
	{
		if (i == len - 1)
		{
			printf("%05d %d -1\n", v[i].local, v[i].data);
		}
		else
		{
			printf("%05d %d %05d\n", v[i].local, v[i].data, v[i+1].local);
		}
	}

	return;
}

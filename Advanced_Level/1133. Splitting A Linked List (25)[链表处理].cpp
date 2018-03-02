#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int loca, da, next;
};

const int Max = 100000;
Node H[Max];
int head, N, K;
vector<Node *> re;
/*
题意：链表处理题
将一杂乱的链表按照一定格式（负的在前，大于给定值的在后）重新排列。
思路：
先把每个结点存储在数组里，
然后遍历3次，存入vector里，最后输出即可。
已AC
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d %d", &head, &N, &K);
	int add;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &add);
		scanf("%d %d", &H[add].da, &H[add].next);
		H[add].loca = add;
	}
	
	add = head;
	while (add != -1)
	{
		if (H[add].da < 0)
			re.push_back(&H[add]);
		add = H[add].next;
	}
	add = head;
	while (add != -1)
	{
		if (H[add].da >= 0 && H[add].da <= K)
			re.push_back(&H[add]);
		add = H[add].next;
	}
	add = head;
	while (add != -1)
	{
		if (H[add].da > K)
			re.push_back(&H[add]);
		add = H[add].next;
	}

	for (int i = 0; i < re.size(); i++)
	{
		if (i != re.size() - 1)
			printf("%05d %d %05d\n", re[i]->loca, re[i]->da, re[i + 1]->loca);
		else
			printf("%05d %d -1\n", re[i]->loca, re[i]->da);
	}

	return 0;
}

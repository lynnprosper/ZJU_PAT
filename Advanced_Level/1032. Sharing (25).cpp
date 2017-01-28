#include<iostream>
using namespace std;

struct Node	//链表的结点
{
	char ch;	//存储字符
	int next;	//下一个地址
};
const int M = 100000;
int s1, s2, N;
Node w[M];

int getLen(int s);//取得一个单词的长度

/*
题意：
找两个单词的共同后缀，不过给出的不是链表，
而是静态链表。
思路：
用数组下标模拟链表。分别求出两个单词长度，
然后把词尾对齐，然后逐一比较是否相同。
不要用cin，会超时。
*/
int main()
{
	freopen("in.txt", "r", stdin);
	scanf("%d %d %d", &s1, &s2, &N);

	for (int i = 0; i < N; i++)
	{
		int ad;
		scanf("%d", &ad);
		scanf(" %c %d", &w[ad].ch, &w[ad].next);
	}

	int len1 = getLen(s1);
	int len2 = getLen(s2);
	int p1, p2;
	for(p1 = s1; len1 > len2; len1--)//进行对齐
		p1 = w[p1].next;
	for(p2 = s2; len2 > len1; len2--)
		p2 = w[p2].next;

	while(p1 != -1 || p2 != -1)//逐一比较
	{
		if(p1 == p2)
		{
			printf("%05d\n", p1);
			break;
		}
		p1 = w[p1].next;
		p2 = w[p2].next;
	}
	if(p1 == -1 && p2 == -1)//无相同后缀
		printf("-1\n");

	return 0;
}

int getLen(int s)//取得一个单词的长度
{
	int cnt = 0;
	while(s != -1)
	{
		cnt++;
		s = w[s].next;
	}

	return cnt;
}

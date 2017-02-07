#include<iostream>
using namespace std;

/*
题意：
在M*N个数中，找出占比超过一半的数字。
思路：
有多种方法，最普通的是用数组下标映射数字，记录最大值输出。
还有一种巧妙的方法，即在线处理法。

题目说存在一个主元素，即一个数超过一半。
相当于这个数的个数减去其他不同的个数仍然大于0.
所以，我们可以设置一个变量cur，即当前的主元素，及它的个数cnt。
在读入数据的时候，如果相等，cnt++, 不等就自减。一旦cnt小于0的时候，
那这个数cur肯定不是主元素，更换cur为当前统计的数。
统计完直接输出cur。
不要用cin，超时。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int M, N;
	scanf("%d %d", &M, &N);
	int num = M*N;//总个数
	int cur, cnt = 1;//分别为当前颜色，个数
	scanf("%d", &cur);//先读入第一个，初始化。

	for (int i = 1; i < num; i++)
	{
		int tem;
		scanf("%d", &tem);
		if (cur == tem)//相等，自增
			cnt++;
		else
		{
			cnt--;
			if (cnt < 0)
			{
				cur = tem;//小于0，更换主元素，cnt设为1
				cnt = 1;
			}
		}
	}
	printf("%d\n", cur);

	return 0;
}

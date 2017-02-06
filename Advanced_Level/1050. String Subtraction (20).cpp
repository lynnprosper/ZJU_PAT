#include<iostream>
using namespace std;

/*
题意：
把字符串s1中含有s2中的字符全部去除。
思路：
比较简单。
利用ASCII从0~127的特性，记录s2中的字符十进制形式，然后将对应的
下标元素置为1.最后遍历s1, 其字符在s2中为0则输出。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	char s1[10010], ch;
	int s2[130] = { 0 };//存储ascii的十进制

	int i = 0, j = 0;
	while ((ch = getchar()) != '\n')
		s1[i++] = ch;
	while ((ch = getchar()) != EOF)
		s2[ch] = 1;//置为1

	for (j = 0; j < i; j++)
	{
		if (s2[s1[j]] == 0)
			printf("%c", s1[j]);
	}
	printf("\n");

	return 0;
}

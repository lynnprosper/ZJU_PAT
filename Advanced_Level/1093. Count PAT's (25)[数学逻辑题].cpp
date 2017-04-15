#include <iostream>
#include <string>
using namespace std;

/*
题意：数学逻辑题。数出字符串里有多少个PAT。
思路：这题卡时间，O必须是线性n。思路不是很好想。
想法有点类似贪心。
比如我们在遍历字符时，遇到了一个T，那么前面有多少个PA，
PAT就可以增加多少个PA*1.
同样，如何得出前面多少个PA呢， 一样的道理。
已AC.
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	string str;
	cin >> str;

	long long p, pa, pat;//用长整型
	p = pa = pat = 0;
	for (int i = 0; i < str.length(); i++)//遍历字符
	{
		if (str[i] == 'P')
		{
			p++;
		}
		else if (str[i] == 'A')
		{
			pa += p;
		}
		else
		{
			pat += pa;
		}
	}

	printf("%lld\n", pat % 1000000007);

	return 0;
}

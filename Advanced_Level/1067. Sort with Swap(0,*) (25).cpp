#include<iostream>
#include<map>
using namespace std;

/*
题意：
交换排序，不过每次只能和元素交换，输出最少交换次数。
思路：
如何交换才能最少？显然，如果每次交换把一个元素换到正确位置，
最终次数就是最少。
通过样例二，我们发现，当把0换到位置0时，还有元素未在正确位置，
此时，需要把0和未在正确位置的元素互换（浪费了一次，但是必须的）
再继续进行。
有多种方法，可以用数组，也可以用map。
我这里用的map。key记录元素值，value记录位置。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	map<int, int> np;
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		if (num == 0 || num != i)//不在正确位置或者元素0插入map。
			np[num] = i;
	}

	int cnt = 0;
	map<int, int>::const_iterator it;
	while (1)
	{
		if (np[0] == 0)//把0换到位置0时，还有元素未在正确位置，
		{
			if (np.size() == 1)//交换完毕
				break;
			else
			{
				it = np.begin();
				it++;//第一个不在正确位置的元素
				np[0] = it->second;
				np[it->first] = 0;
				cnt++;
			}
		}
		else
		{
			int pos = np[0];
			np[0] = np[pos];//交换后元素0所在位置
			np.erase(pos);
			cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}

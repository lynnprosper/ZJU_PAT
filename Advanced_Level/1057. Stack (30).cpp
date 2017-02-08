#include<iostream>
#include<stack>
#include<vector>
#include<set>
#include<functional>//使用仿函数greater<int>
using namespace std;

/*
题意：
题目关键是求栈的中位数。
思路：
一般方法会超时。必须是O（1）或者O(log)求中位数才不会。
可以用树状数组，或者用集合模拟大小堆。
我用的是集合（multiset).
一个small（小根堆），保存后一半。big(大根堆)，保存前一半元素。大根堆与小根堆的元素个数相等（偶数），
或者多1个（奇数），这样大根堆堆顶即是中位数。
已AC。
部分参考自：http://blog.csdn.net/kakitgogogo/article/details/51926600
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N;
	char s[15];
	stack<int> st;
	multiset<int> small;//小根堆
	multiset<int, greater<int> > big;//大根堆
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", s);
		if (s[1] == 'o')
		{
			if (st.empty())
				printf("Invalid\n");
			else
			{
				int num = st.top();
				printf("%d\n", num);
				if (num > *big.begin())
					small.erase(small.find(num));//删除不能用值做参数，会删除多个。
				else
					big.erase(big.find(num));
				st.pop();
			}
		}
		else if (s[1] == 'u')
		{
			int num;
			scanf("%d", &num);
			st.push(num);
			if (!big.empty() && num > *big.begin())
				small.insert(num);
			else
				big.insert(num);
		}
		else
		{
			if (big.empty())
				printf("Invalid\n");
			else
				printf("%d\n", *big.begin());
		}

		if (small.size() > big.size())//对两个堆进行维护，确保符合要求。
		{
			big.insert(*small.begin());
			small.erase(small.begin());
		}
		else if (big.size() > small.size() + 1)
		{
			small.insert(*big.begin());
			big.erase(big.begin());
		}
	}

	return 0;
}

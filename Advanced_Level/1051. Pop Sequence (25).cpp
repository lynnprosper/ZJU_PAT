#include<iostream>
#include<stack>
using namespace std;
/*
题意:
给定入栈序列1~N，判断给出的出栈序列是否可能。
思路：
数据栈的问题。
直接利用stl中的栈来模拟就好了。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int M, N, K;
	cin >> M >> N >> K;

	int num;//记录出栈的数值
	for (int i = 0; i < K; i++ )
	{
		int cur = 1;//由于是1~N，直接采用一个变量来记录要入栈的值，省略队列。
		stack<int> s;
		int flag = 1;

		for (int j = 0; j < N; j++)
		{
			cin >> num;
			if (flag)
			{
				while (s.empty() || s.top() != num)//空栈或者栈顶不等当前值，就入栈
				{
					s.push(cur);
					cur++;
					if ((int)s.size() > M)//栈满，则不可能
					{
						flag = 0; 
						break;
					}
				}

				if (flag == 1 && s.top() == num)//相等则出栈
					s.pop();
			}
		}

		if (flag == 1)
			cout << "YES" << endl;
		else
			cout << "NO\n";
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
题意：判断序列中的哪些数可以作为中枢点。排序题。考察快排。
思路：
首先我们要清楚快排中中枢点必然是放在了正确位置上的。
而且要满足前面所有的数都要比它小。
根据这两个条件就可以了。
当然，想不出来的可以试下暴力破解法。
已AC.
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N;
	cin >> N;
	vector<int> origin(N), order(N);//分别存储原始和顺序序列。
	for (int i = 0; i < N; i++)//读入数据
	{
		cin >> origin[i];
	}
	order = origin;
	sort(order.begin(), order.end());
	
	int maxNum = 0;
	int cnt = 0;
	vector<int> pivot;
	for (int i = 0; i < N; i++)
	{
		if (origin[i] > maxNum && origin[i] == order[i])//判断条件
		{
			cnt++;
			pivot.push_back(origin[i]);
			maxNum = origin[i];
		}
		else
			maxNum = max(maxNum, origin[i]);//更新已判断过的最大值。
	}
	
	cout << cnt << endl;
	sort(pivot.begin(), pivot.end());//输出
	for (int i = 0; i < pivot.size(); i++)
	{
		if (i != 0)
			cout << ' ';
		cout << pivot[i];
	}
	cout << endl;

	return 0;
}

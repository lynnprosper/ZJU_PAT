#include<iostream>
#include<vector>
#include<algorithm>//使用max函数
using namespace std;

/*
题意：
给定一个子串及总串，求总串最长的子串序列（可重复及不连续）。
思路：
算法逻辑题。核心思想是动态规划（全局最优必定包含某个局部最优）。
这是LCS(最长公共序列不连续）的变形。该题允许重复。
动态规划关键是写出状态及状态转移方程。
分析：
设喜欢的颜色1~mc， 给定的1~lc， 解的集合dp[mc]（表示给定颜色数mc时的最大匹配长度，是最优解）;
当我们对第m个喜欢的颜色和第l个待定颜色匹配时，
若：
1、此时my[m] = giv[l]， 那么喜欢颜色数m的解dp[m]就在原来基础上加1
（因为多匹配了一个，当然加1啦）。
2、不等，匹配失败，那解dp[m]怎么处理？
	此时我们要回顾下之前的情况，即m-1个时候长度是多少（匹配失败，不能只顾自己啦
	，要考虑以前的）。如果dp[m-1] > dp[m]， 那么第m个颜色无法匹配，且目前还没有上一个的多，
	取上一个值就好了。
以上是状态转移方程的文字描述。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int mc, lc, n;
	cin >> n >> mc;//n 其实没用
	vector<int> my(mc + 1, 0);//这里习惯用容器，也可以用数组
	for (int i = 1; i <= mc; i++)
		cin >> my[i];//喜欢的颜色，从1而不是0开始，方便和下面的dp数组一致，且0的时候为0也是有意义。
	cin >> lc;
	vector<int> giv(lc + 1, 0);//给定的颜色
	for (int i = 1; i <= lc; i++)
		cin >> giv[i];

	int m, l;
	vector<int> dp(mc + 1, 0);//状态转移的算法描述
	for (l = 1; l <= lc; l++)
	{
		for (m = 1; m <= mc; m++)
		{
			if (my[m] == giv[l])
				dp[m]++;
			else
				dp[m] = max(dp[m], dp[m - 1]);//匹配失败，选最大的喽
		}
	}
	cout << dp[mc] << endl;

	return 0;
}

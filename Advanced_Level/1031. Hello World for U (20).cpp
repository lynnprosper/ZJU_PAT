#include<iostream>
#include<string>
#include<iomanip>	//使用输出流操纵算子
using namespace std;
/*
题意：
根据给定字符串，输出符合条件的“U”形字符串。
思路：
关键是如何确定三边的边长。
常规做法是一点点试探。
其实从条件中我们可以发现两条竖边尽可能地接近横边。
然后我们可以得出n1 = （N+2）/3这个规律。
剩下就直接输出啦
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	string s;
	cin >> s;
	int N = s.size();
	int n1 = (N+2)/3;
	int n2 = N - 2*n1;

	int start = 0;//起点
	int end = N-1;//末点
	for(int i = 1; i < n1; i++)
		cout << s[start++] << setw(n2) << setfill(' ') << " "
		<< s[end--] << endl;
	cout << s.substr(start, n2+2) << endl;//输出最后一行

	return 0;
}

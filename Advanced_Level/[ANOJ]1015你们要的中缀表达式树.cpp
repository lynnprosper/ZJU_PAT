#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;

struct Node
{
	Node() :left(-1), right(-1){}
	string da;
	int left, right;
};

int N, H[31] = { 0 }, T;
vector<Node> mv;

double in_order(int x);

/*
题意：二叉树遍历题。
思路：
核心是中序遍历。
只是除最外层，都要加上括号输出。
值的计算问题，递归计算即可。
注意：计算的变量要用double，可能很大。
已AC
*/

int main()
{
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	cin >> N;
	mv.resize(N);
	for (int i = 0; i < N; i++)
		cin >> mv[i].da;
	string sa, sb;
	for (int i = 0; i < N; i++)
	{
		cin >> sa >> sb;
		if (sa[0] != '-')
		{
			mv[i].left = atoi(sa.c_str()); //***字符串转数字
			H[mv[i].left] = 1;
		}
		if (sb[0] != '-')
		{
			mv[i].right = atoi(sb.c_str());
			H[mv[i].right] = 1;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (H[i] == 0)
		{
			T = i;	//***找出根节点
			break;
		}
	}
	printf(" %.2f\n", in_order(T));

	return 0;
}

double in_order(int x)
{
	if (mv[x].left < 0 && mv[x].right < 0) //***这里是叶子结点
	{
		cout << mv[x].da;
		return atof(mv[x].da.c_str());
	}

	double dl, dr;
	if (x != T)
		cout << "(";
	dl = in_order(mv[x].left);
	cout << mv[x].da;
	dr = in_order(mv[x].right);
	if (x != T)
		cout << ")";
	switch (mv[x].da[0])
	{
	case '+':
		return (dl + dr);
		break;
	case '-':
		return (dl - dr);
		break;
	case '*':
		return (dl * dr);
		break;
	case '/':
		return (dl / dr);
		break;
	}
	return 0;
}

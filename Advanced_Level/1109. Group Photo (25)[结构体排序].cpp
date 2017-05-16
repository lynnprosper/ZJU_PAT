#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node//学生的结构体
{
	bool operator< (const Node &b)//重载比较运算符， 降序排序
	{
		if (m_ht > b.m_ht)//高的在前
			return true;
		else if (m_ht == b.m_ht)
		{
			if (m_name < b.m_name)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	string m_name;
	int m_ht;
};

void Print(vector<string> &v);//输出

/*
题意：结构体排序。
把题意翻译过来，就是按照“身高->名字的字母序”优先级排序。
然后对于每一排，最高的在中间，然后在高的左右依次排位置。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N, K;
	cin >> N >> K;
	vector<Node> stu(N);
	for (int i = 0; i < N; i++)
	{
		cin >> stu[i].m_name >> stu[i].m_ht;
	}
	sort(stu.begin(), stu.end());

	int m = N / K;
	int lastRow = m + N%K;
	vector<string> re(lastRow);//输出结果先存储在这里
	int mid = lastRow / 2;
	re[mid] = stu[0].m_name;
	for (int i = 1; i < lastRow; i++)//先处理最后一排
	{
		if (i % 2 == 0)
		{
			re[mid + i / 2] = stu[i].m_name;//插在高的右边
		}
		else
		{
			re[mid - 1 - i / 2] = stu[i].m_name;//插在高的左边
		}
	}
	Print(re);

	int start = lastRow;
	re.clear();
	re.resize(m);
	mid = m / 2;
	for (int j = 1; j < K; j++)//处理一般情况
	{
		re[mid] = stu[start].m_name;
		for (int i = 1; i < m; i++)
		{
			if (i % 2 == 0)
			{
				re[mid + i / 2] = stu[start+i].m_name;
			}
			else
			{
				re[mid - 1 - i / 2] = stu[start + i].m_name;
			}
		}

		Print(re);
		start += m;
	}

	return 0;
}

void Print(vector<string> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (i != 0)
			cout << ' ';
		cout << v[i];
	}
	cout << endl;
}

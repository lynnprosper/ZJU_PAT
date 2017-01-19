#include<iostream>
#include<algorithm>	//sort()
#include<iomanip>	//控制输出流
using namespace std;

struct Node	//结构体，保存每场比赛的赔率。
{
	int pos;	//表示0,1,2中的一个。
	double odd;	//赔率
	bool operator<(const Node &a) const	//重载比较运算符
	{
		return odd > a.odd;	//降序
	}
};

/*
思路：题意是给出三场比赛的胜负平的赔率（题目给出的是1赔几）
投入2块（即两倍注），求出最大赢利。
基本的I/O问题。有很多方法，数组，模板STL都可以。
我定义了一个结构体。
注意：最后的结果两位小数，四舍五入。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	Node tem[3];
	Node result[3];	//保存每场比赛的最大赔率；
	char ch[3] = {'W', 'T', 'L'};	//与结构中的pos建立映射关系；

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cin >> tem[j].odd;
			tem[j].pos = j;
		}

		sort(tem, tem+3);
		result[i].odd = tem[2].odd;	//保存结果
		result[i].pos = tem[2].pos;
	}

	double profit = 1.3;	//此处对公式进行了简化，下同
	for(int i = 0; i < 3; i++)
	{
		cout << ch[result[i].pos] << ' ';
		profit *= result[i].odd;
	}
	cout << fixed << setprecision(2)
		<< profit + 0.001 - 2 <<endl;	//cout四舍五入是取最近的偶数，加0.001校正

	return 0;
}

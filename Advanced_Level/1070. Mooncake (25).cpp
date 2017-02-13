#include<iostream>
#include<algorithm>//使用sort函数
#include<vector>
using namespace std;

struct Node
{
	bool operator<(const Node &b) const//重载比较运算符
	{
		return unit > b.unit;
	}
	double amount, price, unit;//分别为数量， 总价， 单价
};

/*
题意：求组合产品的最大利润。
思路：
结构体排序题。排序后，从大到小依次累计利润就好了。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N, D;
	cin >> N >> D;//产品数目， 需求总量
	vector<Node> pro(N);//存储每种产品
	
	for (int i = 0; i < N; i++)
		cin >> pro[i].amount;
	for (int i = 0; i < N; i++)
	{
		cin >> pro[i].price;
		pro[i].unit = pro[i].price / pro[i].amount;
	}
	sort(pro.begin(), pro.end());//降序

	double profit = 0;
	int i = 0;
	while (D > 0 && i < N)//循环累计
	{
		if (pro[i].amount > D)
		{
			profit += pro[i++].unit*D;
			D = 0;
		}
		else
		{
			profit += pro[i].price;
			D -= pro[i++].amount;
		}
		
	}
	printf("%.2f\n", profit);

	return 0;
}

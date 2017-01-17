#include<iostream>
#include<map>
using namespace std;

/*
思路： 题意是求两多项式的乘积。有多种数据结构，可以用链表，
或者STL中的set，map等。然后就是逐项相乘啦。
为求算法简便，选用map。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	map<int, double> m1, m2, m3;	//定义三个容器；
	int k1, k2, i, exp;
	double coe;
	cin >> k1;	//读取数据；
	for(i = 0; i < k1; i++)
	{
		cin >> exp >> coe;
		m1[exp] = coe;	//插入容器；
	}
	cin >> k2;
	for(i = 0; i < k2; i++)
	{
		cin >> exp >> coe;
		m2[exp] = coe;
	}

	map<int, double>::iterator it1, it2;	//定义两个正向迭代器
	for(it1 = m1.begin(); it1 != m1.end(); it1++)
	{
		for(it2 = m2.begin(); it2 != m2.end(); it2++)	//逐项相乘；
		{
			exp = it1->first + it2->first;
			coe = it1->second * it2->second;
			if(m3.count(exp))	//判读含exp的项是否存在；
			{
				m3[exp] += coe;
				if(m3[exp] == 0)	//系数为0删除该项；
					m3.erase(exp);
			}
			else
				m3[exp] = coe;
		}
	}

	cout << m3.size();
	map<int, double>::reverse_iterator rit;	//定义反向迭代器，map默认是按照key升序。
	for(rit = m3.rbegin(); rit != m3.rend(); rit++)
		printf(" %d %.1lf", rit->first, rit->second);
	cout <<endl;

	return 0;
}

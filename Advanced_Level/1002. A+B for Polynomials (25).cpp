#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Node
{
	Node():exp(0), coe(0) {}
	int exp;
	double coe;
};
/*
思路：我用的是数组方式，有些复杂，简单方法是把数组下标作为映射。
注：系数需为double，float无法AC, 且系数为0不需输出。
*/

int main()
{
	//freopen("in.txt", "r", stdin);
	int k1, k2, i, j;
	cin >> k1;
	Node *p1 = new Node[k1];
	for(i = 0; i<k1; i++)
		cin>>p1[i].exp >> p1[i].coe;
	cin >> k2;
	Node *p2 = new Node[k2];
	for(i = 0; i<k2; i++)
		cin>>p2[i].exp >> p2[i].coe;
	//cout<<k1;

	Node tem;
	vector<Node> v;
	for(i = 0, j = 0; i < k1 && j < k2; )
	{
		if(p1[i].exp == p2[j].exp)
		{
			tem.exp = p1[i].exp;
			tem.coe = p1[i].coe + p2[j].coe;
			if(tem.coe != 0)
				v.push_back(tem);
			i++;
			j++;
		}
		else if(p1[i].exp > p2[j].exp)
		{
			v.push_back(p1[i]);
			i++;
		}
		else
		{
			v.push_back(p2[j]);
			j++;
		}
	}
	while(i< k1)
		v.push_back(p1[i++]);
	while(j <k2)
		v.push_back(p2[j++]);

	int len = v.size();
	printf("%d", len);
	for(i = 0; i < len; i++)
		printf(" %d %.1lf", v[i].exp, v[i].coe);
	printf("\n");

	delete[] p1, p2;
	return 0;
}

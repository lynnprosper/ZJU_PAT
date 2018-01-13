#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
	bool operator< (const Node &b)
	{
		return (dist < b.dist);
	}
	float price, dist;
};

int Cap, D, Av, N, R;
float sum = 0;
vector<Node> mv;

void gd();

int main()
{
	freopen("in.txt", "r", stdin);
	scanf("%d %d %d %d", &Cap, &D, &Av, &N);
	R = Av*Cap;
	mv.resize(N + 1);
	for (int i = 0; i < N; i++)
	{
		scanf("%f %f", &mv[i].price, &mv[i].dist);
	}
	mv[N].price = 0;
	mv[N].dist = D;
	sort(mv.begin(), mv.end());
	if (mv[0].dist != 0)
	{
		printf("The maximum travel distance = 0.00\n");
	}
	else
	{
		gd();
	}

	return 0;
}

void gd()
{
	float dis = 0, curcap = 0;
	int pos = 0;
	while (1)
	{
		if (dis == D)
			break;

		int npos = -1;
		int flag = 0;
		for (int i = pos + 1; i <= N; i++)
		{
			if (mv[i].dist - mv[pos].dist > R)
			{
				if (npos < 0)
					npos = i - 1;
				break;
			}

			if (mv[i].price <= mv[pos].price)
			{
				npos = i;
				flag = 1;
				break;
			}
		}

		if (npos == pos)
		{
			printf("The maximum travel distance = %.2f\n", dis+R);
			break;
		}
		else if (flag == 0)
		{
			sum += (Cap-curcap) * mv[pos].price;
			dis = mv[npos].dist;
			curcap = Cap - (mv[npos].dist - mv[pos].dist) / Av;
			pos = npos;
		}
		else
		{
			sum += ((mv[npos].dist - mv[pos].dist) / Av - curcap)*mv[pos].price;
			dis = mv[npos].dist;
			curcap = 0;
			pos = npos;
		}
	}

	if (dis == D)
	{
		printf("%.2f\n", sum);
	}

	return;
}

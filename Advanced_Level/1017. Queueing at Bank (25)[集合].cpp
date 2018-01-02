#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	bool operator< (const Node &b)
	{
		if (at < b.at)
			return true;
		else
			return false;
	}
	Node(int a, int b) : at(a), pt(b) {}
	int at;
	int pt;
};
int N, K, cnt = 0;
int sta = 8 * 3600;
int et = 17 * 3600;

int main()
{
	freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	multiset<int> st;
	vector<Node> mv;
	for (int i = 0; i < K; i++)
	{
		st.insert(sta);
	}

	int hh, mm, ss, pro, arrive;
	for (int i = 0; i < N; i++)
	{
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &pro);
		arrive = hh * 3600 + mm * 60 + ss;
		if (arrive <= et)
		{
			mv.push_back(Node(arrive, pro * 60));
		}
	}
	//printf("%d\n", st.size());
	sort(mv.begin(), mv.end());

	int size = mv.size();
	for (int i = 0; i < size; i++)
	{
		auto it = st.begin();
		int cur = *it;
		st.erase(it);
		int sub = cur - mv[i].at;
		if (sub > 0)
		{
			cnt += sub;
			cur += mv[i].pt;
			st.insert(cur);
		}
		else
		{
			cur = mv[i].at + mv[i].pt;
			st.insert(cur);
		}
	}

	float re = (float)cnt / 60 / size;
	printf("%.1f\n", re);

	return 0;
}

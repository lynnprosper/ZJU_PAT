#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

char tg[4] = { 'A', 'C', 'M', 'E' };
struct Node
{
	int id, tag;
	int g[4];
};
struct Flag
{
	Flag() : rk(0), tag(0)  {}
	Flag(int a, int b) : rk(a), tag(b) {}
	int rk, tag;
};

bool cmpa(Node &a, Node &b)
{
	if (a.g[0] > b.g[0])
		return true;
	else
		return false;
}
bool cmpc(Node &a, Node &b)
{
	if (a.g[1] > b.g[1])
		return true;
	else
		return false;
}
bool cmpm(Node &a, Node &b)
{
	if (a.g[2] > b.g[2])
		return true;
	else
		return false;
}
bool cmpe(Node &a, Node &b)
{
	if (a.g[3] > b.g[3])
		return true;
	else
		return false;
}
int N, M;
vector<Node> mv;
map<int, Flag> mp;
void GetRank(int tag);

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	mv.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d", &mv[i].id, &mv[i].g[1], &mv[i].g[2], &mv[i].g[3]);
		mv[i].g[0] = mv[i].g[1] + mv[i].g[2] + mv[i].g[3];
	}

	sort(mv.begin(), mv.end(), cmpa);
	GetRank(0);
	sort(mv.begin(), mv.end(), cmpc);
	GetRank(1);
	sort(mv.begin(), mv.end(), cmpm);
	GetRank(2);
	sort(mv.begin(), mv.end(), cmpe);
	GetRank(3);

	for (int i = 0; i < M; i++)
	{
		int tid;
		scanf("%d", &tid);
		if (mp.count(tid) < 1)
		{
			printf("N/A\n");
		}
		else
		{
			printf("%d %c\n", mp[tid].rk, tg[mp[tid].tag]);
		}
	}
	//printf("%d", mv[0].id);

	return 0;
}

void GetRank(int tag)
{
	int lastgrade = -1, lastrank;
	for (int i = 0; i < N; i++)
	{
		int current;
		if (mv[i].g[tag] != lastgrade)
		{
			current = i + 1;
			lastgrade = mv[i].g[tag];
			lastrank = current;
		}
		else
		{
			current = lastrank;
		}

		if (mp.count(mv[i].id) < 1)
		{
			Flag tm(current, tag);
			mp.insert(make_pair(mv[i].id, tm));
		}
		else
		{
			if (mp[mv[i].id].rk > current)
			{
				mp[mv[i].id].rk = current;
				mp[mv[i].id].tag = tag;
			}
		}
	}
}

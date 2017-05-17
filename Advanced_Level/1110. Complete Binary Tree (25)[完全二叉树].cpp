#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Node	//存储结点信息
{
	int m_left, m_right;
};

/*
题意：完全二叉树题。判断一棵树是否CBT。
思路：
完全二叉树的特点：叶子结点只能在最后出现，不能夹在非叶子结点间。
直接用层序遍历好了。
利用队列进行bfs（广度搜索），当遍历到结点是-1（表示空），则已遍历的结点数
应该为N，则是CBT。
最后一个结点遍历的时候更新即可。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int N;
	cin >> N;
	vector<Node> v(N);//存储二叉树结点
	vector<int> child(N, 0);//用了判断根
	for (int i = 0; i < N; i++)
	{
		string a, b;//注意，不能用char，数字可能大于9.
		cin >> a >> b;
		if (a == "-")
		{
			v[i].m_left = -1;
		}
		else
		{
			sscanf(a.c_str(), "%d", &v[i].m_left);//字符串转数字
			child[v[i].m_left] = 1;
		}

		if (b == "-")
		{
			v[i].m_right = -1;//表示子结点空
		}
		else
		{
			sscanf(b.c_str(), "%d", &v[i].m_right);
			child[v[i].m_right] = 1;
		}
	}

	int root;
	for (int i = 0; i < N; i++)//找到根结点
	{
		if (child[i] == 0)
		{
			root = i;
			break;
		}
	}

	queue<int> Q;
	Q.push(root);
	int cnt = 0;
	int lastNode;
	while (!Q.empty())
	{
		int curNode = Q.front();//遍历的当前结点
		Q.pop();
		if (curNode != -1)
		{
			cnt++;
			lastNode = curNode;//更新最后一个结点
			Q.push(v[curNode].m_left);
			Q.push(v[curNode].m_right);
		}
		else
		{
			if (cnt == N)
			{
				cout << "YES " << lastNode << endl;
				break;
			}
			else
			{
				cout << "NO " << root << endl;
				break;
			}
		}
	}
		
	return 0;
}

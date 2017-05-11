#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node//结点结构体
{
	int id;//当前结点值
	int left, right;//左右结点值
};
int N, root;//分别为总结点数和根结点值
vector<Node> btree;//存储二叉树
vector<int> nid, outData;//分别为判断根和输出结果的数组

void LevelOrder();//层序遍历
void InOrder(int num);//中序遍历

/*
题意：树的遍历题。
给出一颗二叉树，输出反转后的层序和中序。
思路：
既然要反转，我们可以在存储结点时，直接把左右孩子交换存储。
同时判断哪个时根结点，没有出现的值即是根结点。这里用的nid数组进行判断。
层序遍历就是常规的用队列输出了。
中序用递归遍历即可。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	cin >> N;
	btree.resize(N);
	nid.resize(N);
	for (int i = 0; i < N; i++)//读入数据
	{
		char a, b;
		cin >> a >> b;
		btree[i].id = i;
		btree[i].right = (a == '-' ? -1 : (a - '0'));//交换左右结点
		btree[i].left = (b == '-' ? -1 : (b - '0'));
		
		if (btree[i].left != -1)//标记出现过的结点
			nid[btree[i].left] = 1;
		if (btree[i].right != -1)
			nid[btree[i].right] = 1;
	}


	for (int i = 0; i < N; i++)//找出根结点
	{
		if (nid[i] == 0)
		{
			root = i;
			break;
		}
	}

	LevelOrder();
	InOrder(root);
	for (int i = 0; i < N; i++)//输出中序序列
	{
		if (i != 0)
			cout << ' ';
		cout << outData[i];
	}
	cout << endl;

	return 0;
}

void LevelOrder()//层序遍历
{
	queue<int> Q;
	Q.push(root);
	bool first = true;

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		
		if (btree[cur].left != -1)
			Q.push(btree[cur].left);
		if (btree[cur].right != -1)
			Q.push(btree[cur].right);

		if (!first)
			cout << ' ';
		cout << cur;
		first = false;
	}
	cout << endl;

	return;
}
void InOrder(int num)//中序递归遍历
{
	if (num == -1)
		return;

	InOrder(btree[num].left);
	outData.push_back(num);
	InOrder(btree[num].right);

	return;
}

#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

int N;//结点数
vector<int> ino, pre;//分别存储中序和前序的序列
int findPos(int x);//找出前序中的第x个元素在中序的位置
void post(int left, int right, int ro_pos);//输出后序, 参数分别是中序的左、右边界，前序的根位置

/*
递归＋二叉树的遍历问题
题意：
用栈模拟树的遍历，输出后序
思路：
入栈序列其实是二叉树的前序，出栈序列是中序。
所以，问题就是利用前序和中序输出后序。
显然，用递归处理啦。
已ＡＣ
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	cin >> N;
	stack<int> sta;//栈

	for (int i = 0; i < 2 * N; i++)//读入数据
	{
		string s;
		int data;
		cin >> s;

		if (s[1] == 'u')//构建前序序列
		{
			cin >> data;
			sta.push(data);
			pre.push_back(data);
		}
		else//构建中序序列
		{
			data = sta.top();
			sta.pop();
			ino.push_back(data);
		}
	}
	post(0, N - 1, 0);//递归输出后序

	return 0;
}

int findPos(int x)//找出前序中的第x个元素在中序的位置
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (ino[i] == pre[x])
			break;
	}

	return i;
}

void post(int left, int right, int ro_pos)//参数分别是中序的左、右边界，前序的根位置
{
	if (left > right)//递归终止条件
		return;

	int ino_pos = findPos(ro_pos);
	post(left, ino_pos - 1, ro_pos + 1);//递归左子树
	post(ino_pos + 1, right, (ro_pos + ino_pos - left + 1));//递归右子树

	if (ro_pos == 0)//输出根结点
		cout << pre[ro_pos] << endl;
	else
		cout << pre[ro_pos] << ' ';
}

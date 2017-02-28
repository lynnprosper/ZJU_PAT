#include<iostream>
#include<vector>
using namespace std;

int N;//元素个数
int flag = 1;//标记是否唯一
vector<int> pre, ino, post;//分别存储前序，中序及后序序列
void getIno(int prleft, int prright, int poleft, int poright);//分治递归获取中序序列
int findpos(int index);//查找后序某下标index元素在前序的位置。

/*
题意：
给出前序和后序序列，输出中序序列。
若不唯一，输出任意一个即可。
思路：
二叉树遍历题。类似前序和中序求后序。
这里只不过由于前序和后序不能唯一确定一个二叉树。
首先，我们要分析为什么不能确定呢。
我们知道前序是中左右， 后序是左右中。
如果每个结点都有左右孩子，则可以确定。
否则，有一个孩子时，我们不知道这个孩子是左还是右，于是就不能唯一确定了。

知道不能确定的原因后，我们还要输出一个，就可以假设一个孩子时都是右孩子就好了。
获取中序依然用分治法递归处理。函数参数就是前序的左右边界，后序的左右边界。
前序的根是最左， 该根在后序位置是最右。
然后最右前一个是根的右孩子，找出该结点在前序的位置k， 这样前序中k前是左子树部分，
k后面是右子树部分。递归的边界划分就出来了。
已AC。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> N;
	pre.resize(N);
	post.resize(N);
	for (int i = 0; i < N; i++)//读入数据
		cin >> pre[i];
	for (int i = 0; i < N; i++)
		cin >> post[i];

	getIno(0, N - 1, 0, N - 1);//取得中序序列
	if (flag == 1)
		cout << "Yes\n";
	else
		cout << "No\n";
	
	for (int i = 0; i < N; i++)
	{
		if (i != 0)
			cout << ' ';
		cout << ino[i];
	}
	cout << endl;

	return 0;
}

void getIno(int prleft, int prright, int poleft, int poright)//分治递归获取中序序列
{
	if (prleft == prright)//递归结束条件，树中只有一个结点
	{
		ino.push_back(post[poright]);
		return;
	}

	int x = findpos(poright - 1);//找出根的右孩子在前序位置
	if ((x - prleft) > 1)//说明根有左孩子，否则两者相差1.
	{
		getIno(prleft + 1, x - 1, poleft, poleft + x - prleft - 2);//递归左子树,边界划分可以画下图，有点绕。
		ino.push_back(post[poright]);//把根插入容器
		getIno(x, prright, poleft + x - prleft - 1, poright - 1);//递归右子树
	}
	else//只有一个孩子, 看成右孩子
	{
		flag = 0;
		ino.push_back(post[poright]);//先访问根，再递归右子树
		getIno(prleft + 1, prright, poleft, poright - 1);
	}

	return;
}

int findpos(int index)//查找后序某下标index元素在前序的位置。
{
	for (int i = 0; i < N; i++)
	{
		if (pre[i] == post[index])
			return i;
	}

	return -1;
}

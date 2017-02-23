#include<iostream>
#include<algorithm>//使用sort和swap函数
#include<vector>
using namespace std;

int N;//元素数
vector<int> ini, jud;//分别为初始和待判断序列
int isInsert();//判断是否插入，返回1和0
void print();//输出序列
void heapSort();//堆排序
void adjustDown(int n);//将堆顶元素向下调整成为一个新堆

/*
题意：
插入与堆排序判断。
思路：
插入排序特点：前i个元素有序，后面的和原序列相等。
大根堆排序特点： 后面j个元素有序，第一个元素为前N-j个元素的最大值，且小于后j个。
搞清楚特点就简单了。
先判断是否插入。
若不是，进行堆排。
已AC
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	cin >> N;
	ini.resize(N+1);//为便于堆的特点，即a[i] > a[2*i] 即a[2*i+1]，从1开始。0无法处理
	jud.resize(N+1);
	for (int i = 1; i <= N; i++)
		cin >> ini[i];
	for (int i = 1; i <= N; i++)
		cin >> jud[i];

	if (isInsert() == 1)//插入
		return 0;
	else
		heapSort();//堆排序

	return 0;
}

int isInsert()//判断是否插入，返回1和0
{
	int i;
	for (i = 1; i < N && jud[i] <= jud[i + 1]; i++);//找出无序的位置
	int pos = i + 1;

	for (int j = pos; j <= N; j++)//判断后面的是否一致
	{
		if (ini[j] != jud[j])
			return 0;
	}

	cout << "Insertion Sort\n";
	sort(jud.begin()+1, jud.begin() + pos + 1);//排序输出
	print();
	return 1;
}

void heapSort()//堆排序
{
	int pos;
	for (pos = N; pos > 0 && jud[1] <= jud[pos]; pos--);//找出需要调整的位置

	if (pos != 1)
	{
		swap(jud[1], jud[pos]);//堆顶和末尾进行交换
		adjustDown(pos - 1);//对交换后的调整成新堆
	}

	cout << "Heap Sort\n";
	print();
	return;
}

void adjustDown(int n)//将堆顶元素向下调整成为一个新堆
{
	int x = jud[1];//保存堆顶元素
	int pa, ch;//分别为父结点编号，子结点编号
	for (pa = 1; pa * 2 <= n; pa = ch)
	{
		ch = pa * 2;
		if (ch < n && jud[ch] < jud[ch + 1])//找出子结点较大的那个
			ch++;

		if (x < jud[ch])//子结点比父结点大
			jud[pa] = jud[ch];
		else
			break;
	}
	jud[pa] = x;

	return;
}

void print()
{
	for (int i = 1; i <= N; i++)
	{
		if (i == 1)
			cout << jud[i];
		else
			cout << ' ' << jud[i];
	}
	cout << endl;
}

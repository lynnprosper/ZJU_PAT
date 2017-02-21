#include<iostream>
#include<algorithm>//使用sort函数
#include<vector>
using namespace std;

int N;//元素数目
vector<int> ini;//初始序列
vector<int> jud;//待判断序列
int isInsert();//判断是否插入排序，若是，进行下一步排序
void merge();//归并序列
void print();//输出结果

/*
题意：
插入与归并排序问题。
思路：
插入排序是前i个元素有序，后面的和原序列一致。
归并是每k个元素内部有序。
有多种方法。

若是插入，则直接对i+1个进行排序就好了。
归并的话，可以求出目前的归并段k是几，再归并一次就好了。
也可以对原序列直接归并，每次归并后判断是否等于给出的序列。
若是，再归并一次。

此处用的第二种。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	cin >> N;
	ini.resize(N);//重定义容器大小
	jud.resize(N);

	for (int i = 0; i < N; i++)
		cin >> ini[i];
	for (int i = 0; i < N; i++)
		cin >> jud[i];

	if (isInsert() == 1)//是插入排序
		return 0;
	else
		merge();//归并

	return 0;
}

int isInsert()//判断是否插入排序，若是，进行下一步排序
{
	int pos;
	for (pos = 0; jud[pos] <= jud[pos + 1]; pos++);//求出无序元素的位置
	pos += 1;
	
	for (int i = pos; i < N; i++)//判断后面的元素是否和待判断的一致。若是，则为插入
	{
		if (ini[i] != jud[i])
			return 0;
	}

	cout << "Insertion Sort\n";
	sort(ini.begin(), ini.begin() + pos + 1);//直接用的sort排序。可以自己写插入算法
	print();

	return 1;
}

void merge()//归并序列
{
	int k = 2, flag = 1;//分别为归并段的元素数， 两序列是否相等的标记
	while (flag == 1)//1为不等，继续处理
	{
		flag = 0;
		for (int j = 0; j < N; j++)
		{
			if (ini[j] != jud[j])
			{
				flag = 1;
				break;
			}
		}

		vector<int>::iterator it = ini.begin();
		int i;
		for (i = k; i <= N; i += k)//用sort对每个归并段排序，可以自己写merge算法
			sort(it + i - k, it + i);
		if ((i -= k) < N)
			sort(it + i, ini.end());//处理多余的
		k <<= 1;//归并段数*2
	}

	cout << "Merge Sort\n";
	print();

	return;
}

void print()//输出结果
{
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
			cout << ini[i];
		else
			cout << ' ' << ini[i];
	}
	cout << endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>//使用仿函数中的greater
using namespace std;

int GetColumn(int n);//求出矩阵的列数

/*
题意：数组处理。把一维数组按照某种规则重绘成二维数组形式。
思路:
先对一维数组按照降序排序。
然后按照规则存入二维数组即可。
最后输出。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N;
	cin >> N;
	int column = GetColumn(N);
	int row = N / column;
	vector<vector<int> > matrix(row, vector<int>(column));//二维数组

	vector<int> origin(N);
	for (int i = 0; i < N; i++)
	{
		cin >> origin[i];
	}
	sort(origin.begin(), origin.end(), greater<int>());//降序
	
	int k = 0;
	int left = 0;
	int right = column - 1;
	int top = 0;
	int bottom = row - 1;
	while (k < N)//绘制二维数组，一个循环一圈
	{
		for (int i = left; i <= right && k < N; i++)
			matrix[top][i] = origin[k++];
		for (int i = top + 1; i < bottom && k < N; i++)
			matrix[i][right] = origin[k++];
		for (int i = right; i >= left && k < N; i--)
			matrix[bottom][i] = origin[k++];
		for (int i = bottom - 1; i > top && k < N; i--)
			matrix[i][left] = origin[k++];

		left++;
		right--;
		top++;
		bottom--;
	}
	
	for (int i = 0; i < row; i++)//输出
	{
		for (int j = 0; j < column; j++)
		{
			if (j != 0)
				cout << ' ';
			cout << matrix[i][j];
		}
		cout << endl;
	}

	return 0;
}

int GetColumn(int n)//求出矩阵的列数
{
	int x = (int)sqrt((double)n);
	while (x > 0)
	{
		if (n % x == 0)
			break;
		x--;
	}

	return x;
}

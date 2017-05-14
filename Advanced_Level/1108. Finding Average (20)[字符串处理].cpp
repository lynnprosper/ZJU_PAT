#include<iostream>
#include<cstring>
using namespace std;

double sum = 0;
int cnt = 0;

bool valid(char *str);//用了判断是否有效数字

/*
题意：判断给定的字符串是否有效数字。
思路：
有多个方法。很容易想到对每个字符串进行分析判断，这样也可以，
不过有点麻烦。
另一种方法借助库函数sscanf和sprintf。
sscanf把字符串转换为浮点数tmp，然后用sprintf把tmp转换为字符串
比较两个字符串。不同则不是数字。然后再判断数字是否超出范围。
已AC。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N;
	cin >> N;
	char str[100];
	for (int i = 0; i < N; i++)
	{
		scanf("%s", str);
		if (!valid(str))
		{
			printf("ERROR: %s is not a legal number\n", str);
		}
	}

	if (cnt == 0)
		cout << "The average of 0 numbers is Undefined" << endl;
	else if (cnt == 1)
		printf("The average of 1 number is %.2lf\n", sum);
	else
		printf("The average of %d numbers is %.2lf\n", cnt, sum/cnt);

	return 0;
}

bool valid(char *str)
{
	char str2[100];
	double tmp;
	sscanf(str, "%lf", &tmp);
	sprintf(str2, "%.2f", tmp);//题意是超出2位小数无效。

	if (strlen(str) > strlen(str2))//原字符串长，则无效。短的话，没有关系。
		return false;
	for (int i = 0; i < strlen(str); i++)//判断是否相等
	{
		if (str[i] != str2[i])
			return false;
	}
	if (tmp > 1000.0 || tmp < -1000.0)//判断范围
		return false;

	sum += tmp;
	cnt++;

	return true;
}

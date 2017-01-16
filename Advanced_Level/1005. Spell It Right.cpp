#include<iostream>
using namespace std;

//思路：统计各数位数字和，然后输出英文表示方式；
int main()
{
	char num[10][10] = { "zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine"};
	char in[101];
	cin >>in;
	int sum = 0;
	for(int i = 0; in[i] != '\0'; i++)
		sum += in[i] - '0';
	char result[5];
	sprintf(result, "%d", sum);	//转换为字符串；
	cout << num[result[0]-'0'];
	for(int i = 1; result[i] != '\0'; i++)
		cout << " " << num[result[i]-'0'];
	cout <<endl;

	return 0;
}

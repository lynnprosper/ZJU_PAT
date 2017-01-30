#include<iostream>
#include<algorithm>//使用sort()
#include<sstream>
#include<vector>
#include<string>
using namespace std;

bool cmp(const string &a, const string &b);//sort的比较函数

/*
题意：
根据给定的字符串组合成最小的数。
思路：
显然最后的数是大数，要当成字符串处理。
我们很容易想到升序排序。接下来有一个问题，
即题中所述的出现前缀的情况。这个时候默认的排序显然不正确了。
于是我们必须重新构建比较函数，如何比较呢。
我们不妨先拿出两个字符串a,b.
1.如果a,b 不构成前缀关系，那么默认排序是正确的。
2. a是b的前缀，那组合的结果是两种：ab或ba。
	只要求ab和ba大小就可以了
推而广之，n个字符串按照该规律进行比较。可以发现，2是包含了1的。
ps:
注意特例。
全0，输出0.
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vector<string> sv(n);
	for (int i = 0; i < n; i++)
		cin >> sv[i];
	sort(sv.begin(), sv.end(), cmp);//排序

	stringstream ss;//用stringstream判断最大的数是否0
	ss << sv[sv.size()-1];
	int num;
	ss >> num;
	if(num == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	ss.clear();//用完要清空
	
	ss << sv[0];//处理第一个字符串前面有0的情况
	ss >> num;
	cout << num;
	for (int i = 1; i < n; i++)
		cout << sv[i];
	cout << endl;

	return 0;
}

bool cmp(const string &a, const string &b)
{
	string ab = a+b;
	string ba = b+a;
	return ab < ba;
}

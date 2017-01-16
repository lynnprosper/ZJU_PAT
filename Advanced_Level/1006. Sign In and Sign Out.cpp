#include<iostream>
#include<string>
using namespace std;

//思路：利用string， 可以快速进行判断时间的大小。
int main()
{
	//freopen("in.txt", "r", stdin);
	int n, i;
	string first_id, first_time, last_id, last_time;
	cin >> n;
	cin >> first_id >> first_time >> last_time;
	last_id = first_id;

	string tem[3];	//三个暂存字符串变量；
	for(i =1; i < n; i++)
	{
		cin >> tem[0] >> tem[1] >> tem[2];
		if(tem[1] < first_time)
		{
			first_id = tem[0];
			first_time = tem[1];
		}
		if(tem[2] > last_time)
		{
			last_id = tem[0];
			last_time = tem[2];
		}
	}
	cout << first_id << " " << last_id<<endl;

	return 0;
}

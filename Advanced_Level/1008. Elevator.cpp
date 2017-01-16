#include<iostream>
using namespace std;

const int up_time = 6;
const int down_time = 4;
const int stay_time = 5;

//思路：基本的数学运算。
int main()
{
	//freopen("in.txt", "r", stdin);
	int N, i, sub, sum;
	cin >> N;
	sum = stay_time * N;
	int pre_floor = 0, next_floor;
  
	for(i = 0; i < N; i++)
	{
		cin >> next_floor;
		sub = next_floor - pre_floor;
		if(sub > 0)
			sum += sub*up_time;
		else
			sum += (-sub)*down_time;
		pre_floor = next_floor;
	}
	cout << sum << endl;

	return 0;
}

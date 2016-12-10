#include<iostream>
#include<algorithm>
using namespace std;

//数学运算，输出即可；
int main()
{
	//freopen("in.txt", "r", stdin);
	int N, a, b, i, sum;
	float max, t;
	max = 0;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> a >> b;
		sum = a*a + b*b;
		t = sqrt((float)sum);
		if (t > max)
			max = t;
	}
	printf("%.2f\n", max);


	//system("pause");
	return 0;
}

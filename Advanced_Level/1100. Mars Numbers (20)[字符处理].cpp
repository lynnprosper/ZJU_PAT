#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
题意：字符串处理。地球文和火星文的转换。
思路：
有多种方法。可以把火星文保存成数组，然后解析字符串即可。
我用的是把地球文和火星文进行映射，保存到map里。
注意要点：
火星文个位零不能输出。如26只能输出hel。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	map<int, string> eToM;
	map<string, int> mToe;

	eToM[0] = "tret";
	eToM[1] = "jan";
	eToM[2] = "feb";
	eToM[3] = "mar";
	eToM[4] = "apr";
	eToM[5] = "may";
	eToM[6] = "jun";
	eToM[7] = "jly";
	eToM[8] = "aug";
	eToM[9] = "sep";
	eToM[10] = "oct";
	eToM[11] = "nov";
	eToM[12] = "dec";
	eToM[13] = "tam";
	eToM[26] = "hel";
	eToM[39] = "maa";
	eToM[52] = "huh";
	eToM[65] = "tou";
	eToM[78] = "kes";
	eToM[91] = "hei";
	eToM[104] = "elo";
	eToM[117] = "syy";
	eToM[130] = "lok";
	eToM[143] = "mer";
	eToM[156] = "jou";
	map<int, string>::iterator iter;
	for (iter = eToM.begin(); iter != eToM.end(); iter++)
	{
		mToe.insert(make_pair(iter->second, iter->first));
	}

	int N;
	cin >> N;
	string tmp;
	getchar();//后面是getline读取整行，这里先读掉回车

	for (int i = 0; i < N; i++)
	{
		getline(cin, tmp);
		if (tmp[0] >= '0' && tmp[0] <= '9')//地球文转火星文
		{
			int num;
			sscanf(tmp.c_str(), "%d", &num);
			int firstNum = num / 13 * 13;
			int secondNum = num % 13;

			if (firstNum != 0)//有十位
			{
				cout << eToM[firstNum];
				if (secondNum != 0)//个位不为0
					cout << ' ' << eToM[secondNum];
				cout << endl;
			}
			else
				cout << eToM[secondNum] << endl;
		}
		else//火星文转地球文
		{
			if (tmp.size() > 3)
			{
				cout << mToe[tmp.substr(0, 3)] + mToe[tmp.substr(4)] << endl;
			}
			else
			{
				cout << mToe[tmp] << endl;
			}
		}
	}

	return 0;
}

#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Node	//用户名和密码的结构体
{
	Node(string &n, string &p) : name(n), pw(p) {}
	string name, pw;
};

/*
题意：转换相应的字符。
思路：基础文字处理题，比较简单。
直接用vector，把改过的压入vector里。
*/
int main(void)
{
	//freopen("in.txt", "r", stdin);
	int N;
	cin >> N;
	vector<Node> mo_v;
	for (int i = 0; i < N; i++)
	{
		int flag = 0;
		string id, p;
		cin >> id >> p;

		for (unsigned j = 0; j < p.size(); j++)//转换字符
		{
			switch (p[j])
			{
			case '1':
				p[j] = '@';
				flag = 1;
				break;
			case '0':
				p[j] = '%';
				flag = 1;
				break;
			case 'l':
				p[j] = 'L';
				flag = 1;
				break;
			case 'O':
				p[j] = 'o';
				flag = 1;
				break;
			default:
				break;
			}
		}

		if(flag == 1)//压入vector
		{
			Node no(id, p);
			mo_v.push_back(no);
		}
	}

	if(mo_v.empty() && N == 1)
		cout << "There is " << N << " account and no account is modified"
		<< endl;
	else if (mo_v.empty())
		cout << "There are " << N << " accounts and no account is modified"
		<< endl;
	else
	{
		int m = mo_v.size();
		cout << m << endl;
		for (int i = 0; i < m; i++)
			cout << mo_v[i].name << ' ' 
			<< mo_v[i].pw << endl;
	}

	return 0;
}

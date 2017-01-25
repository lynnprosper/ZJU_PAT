#include<iostream>
#include<string>
#include<sstream> //使用stringstream处理关键字
#include<map>
#include<set>
using namespace std;

/*
题意：
模拟信息检索。数据处理题，逻辑上不难理解。
思路：
既然检索关键字，当然会想到用map。
所以利用5个map，键值存储id。
这里键值类型用的stl中的集合，也可以用vector，再进行排序。
而set默认字典序排列。
为了简便，用了set。
检索输出时，利用key直接输出就好了。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int N;	//总id数
	cin >> N;
	cin.get();	//为了消除数字后的回车，下同。
	map<string, set<string> > mp[6];	//map, 构建了6个，下标0抛弃，1~5分别对应title等。

	for(int i = 0; i < N; i++)	//循环读入数据
	{
		string id, title, author, keys, publish, time;	//id可以用int，但为了方便处理，用string

		getline(cin, id);	//读入一整行。
		getline(cin, title);
		getline(cin, author);
		getline(cin, keys);
		getline(cin, publish);
		getline(cin, time);

		if(mp[1].count(title))	//下面5个map需要单独处理了，虽然有点重复。因为keywords有多个，
			mp[1][title].insert(id);	//需要单独处理。
		else
		{
			set<string> tem;
			tem.insert(id);
			mp[1][title] = tem;
		}

		if(mp[2].count(author))	//键存在，直接插入集合。
			mp[2][author].insert(id);
		else
		{	//键不存在
			set<string> tem;
			tem.insert(id);
			mp[2][author] = tem;
		}

		stringstream ss(keys);	//字符串流ss
		string word;
		while(ss >> word)	//读入关键字
		{
			if(mp[3].count(word))
				mp[3][word].insert(id);
			else
			{
				set<string> tem;
				tem.insert(id);
				mp[3][word] = tem;
			}
		}

		if(mp[4].count(publish))
			mp[4][publish].insert(id);
		else
		{
			set<string> tem;
			tem.insert(id);
			mp[4][publish] = tem;
		}

		if(mp[5].count(time))
			mp[5][time].insert(id);
		else
		{
			set<string> tem;
			tem.insert(id);
			mp[5][time] = tem;
		}
	}
	
	int M;
	cin >> M;	//检索数目
	cin.get();

	for(int i = 0; i < M; i++)	//循环输出
	{
		string buff, tem;
		getline(cin, buff);
		tem = buff.substr(3);	//取得检索字
		int index = buff[0] - '0';	//检索项下标，对应不同map

		cout << buff << endl;
		if(mp[index][tem].empty())
			cout << "Not Found" << endl;
		else
		{
			set<string>::iterator it;	//迭代器处理
			for(it = mp[index][tem].begin(); it != mp[index][tem].end(); it++)
				cout << *it << endl;
		}	
	}

	return 0;
}

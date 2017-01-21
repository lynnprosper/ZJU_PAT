#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int INF = 65535;	//表示无穷大；
struct Person	//顾客结构体
{
	int service_time;	//服务时间
	int leave_time;	//离开时间
};

/*
思路：
题意是银行排队问题。
考查队列和FCFS（先来先服务）.
利用STL中的queue， 模拟银行排队，计算顾客的排队窗口和离开时间。
*/
int main()
{
	//freopen("in.txt", "r", stdin);
	int N;	//窗口数
	int M;	//每队最大容量
	int K;	//顾客数
	int Q;	//查询的人数
	cin >> N >> M >> K >> Q;

	vector<Person> cus(K);	//顾客数组
	for(int i = 0; i < K; i++)	//读入数据，初始化
	{
		cin >> cus[i].service_time;
		cus[i].leave_time = 0;
	}

	vector< queue<int> > line(N);	//N个队列；
	vector<int> t_total(N, 0);	//记录每个队列里的客户离开时间
	int i;
	for(i = 0; i < K && i < N*M; i++)	//队列未满分配客户应该在的队列号。
	{
		int id = i%N;	//应该在的队列号
		line[id].push(i);
		cus[i].leave_time = t_total[id] + cus[i].service_time;
		t_total[id] = cus[i].leave_time;
	}

	for(i; i < K; i++)	//队列满时分配客户应该在的队列号。
	{
		int earliest = INF;	//记录每个队列出队时的最早时间
		int id;
		for(int j = 0; j < N; j++)	//循环找出最早时间
		{
			int first = line[j].front();
			if(cus[first].leave_time < earliest)
			{
				earliest = cus[first].leave_time;
				id = j;
			}
		}
		line[id].pop();	//更新队列
		line[id].push(i);
		cus[i].leave_time = t_total[id] + cus[i].service_time;
		t_total[id] = cus[i].leave_time;
	}

	for( i = 0; i < Q; i++)	//输出
	{
		int q_id;
		cin >> q_id;
		q_id -= 1;	//算法是从0记录的，减去1.
		int startTime = cus[q_id].leave_time - cus[q_id].service_time;
		if(startTime >= 540)
			printf("Sorry\n");
		else
			printf("%02d:%02d\n", cus[q_id].leave_time/60 + 8, cus[q_id].leave_time%60);
	}

	return 0;
}

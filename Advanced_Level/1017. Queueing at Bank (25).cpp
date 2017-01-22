#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct Person	//客户结构体
{
  int arrive_time;	//到达时间
  int service_time;	//需要服务时间
  bool operator< (const Person &b) const //重载比较运算符
  {
    return arrive_time < b.arrive_time;	//升序
  }
};

/*
思路：
题意是计算有效客户的平均等待时间。
由于到达时间无序，需要先排序。然后对每个客户，
记录窗口空闲时的时间，更新客户的等待时间。
为计算方便，时间全部换算成秒。
注：最后一个测试点未过，欢迎指正。
*/
int main()
{
  const int dline = 61200;	//17点对应的秒数
  const int stime = 28800;	//8点开始服务的时间

  //freopen("in.txt", "r", stdin);
  int N, K;	//分别表示总人数， 窗口数
  scanf("%d %d", &N, &K);
  int h, m, s, p;	//分别表示时分秒和服务时间
  vector<Person> cus;	//存储每个有效客户

  for(int i = 0; i < N; i++)
  {
    scanf("%d:%d:%d %d", &h, &m, &s, &p);
    int start = s+ m*60 + h*3600;	//换算成秒的到达时间
    if(start <= dline)	//17点前到的为有效客户，否则忽略
    {
      Person per;
      per.arrive_time = start;
      per.service_time = p*60;
      cus.push_back(per);
    }
  }

  int i, amount = cus.size();	//记录有效客户数
  sort(cus.begin(), cus.end());
  double total = 0;	//总等待时间
  vector<int> service(K);	//记录每个窗口的服务下一个客户的开始时间，编号从0开始

  for(i = 0; i < K; i++)
    service[i] = stime;	//初始化窗口服务时间为8点

  for(i = 0; i < K && i < amount; i++)	//第一次分配客户
  {
    if(cus[i].arrive_time < stime)
    {
      total += stime - cus[i].arrive_time;
      service[i] = stime + cus[i].service_time;
    }
    else
    {
      service[i] = cus[i].arrive_time + cus[i].service_time;
    }
  }
  
  for(i; i < amount; i++)	//处理等候的客户
  {
    int mintime = service[0];	//最早空闲
    int line_id = 0;	//记录最早窗口空闲的编号
    for(int j = 1; j < K; j++)	//取得下一个客户接受服务的窗口
    {
      if(service[j] < mintime)
      {
        mintime = service[j];
        line_id = j;
      }
    }

    if(cus[i].arrive_time < mintime)	//处理该客户
    {
      if(mintime < dline)
        total += mintime - cus[i].arrive_time;
      else
        total += dline - cus[i].arrive_time;	//表示该客户已无法接受服务

      service[line_id] += cus[i].service_time;	//更新空闲时间
    }
    else
      service[line_id] = cus[i].arrive_time + cus[i].service_time;
  }

  cout << fixed << setprecision(1) << total/60/amount << endl;

  return 0;
}

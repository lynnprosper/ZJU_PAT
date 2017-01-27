#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int open_time = 28800;	//开始服务时间
const int close_time = 75600;	//结束服务时间

struct Table	//球桌的结构体
{
  Table() : start_serve(open_time), tag(0) , amount(0) {}//成员初始化
  int start_serve;	//表示什么时候空闲，可以服务下一个
  int tag;	//是否vip桌
  int amount;	//累加服务人数
};

struct Member	//用户的结构体
{
  Member(): service_time(0) {}
  const Member &operator=(const Member &b)	//重载=运算符
  {
    arrive_time = b.arrive_time;
    service_time = b.service_time;
    duration = b.duration;
    return *this;
  }
  int arrive_time;	//到达时间
  int service_time;	//接受服务时间
  int duration;//服务持续时间
};

/*
题意：
数据处理题。比较复杂，要仔细读题。
细节点：
1. 每人最多服务2小时，比如要求3小时，但服务2小时就结束。
有一个测试点好像是4或者5，我陷在这里很久。
2. 等待服务的队列中有vip时，vip优先。
优先细则是，若vip用户可选择多个球桌，vip球桌空的话，选择vip球桌小的编号，
即使普通球桌编号更小，也不会选。
3.21点到达不会被服务。
4.服务时间四舍五入，即5.4m为5， 5.5以上为6m

思路：
做之前最好画个模型，很复杂。
可以采用队列+排序的方式处理（简单些）
也可以用map的有序性，不需要排序。
只是输出的是按照服务时间来排的，不如队列简单些。
我用的map，用两个map，同时维护所有人和vip用户。
核心是在vip的分配上。每当vip球桌空，要先检查是否有vip用户。
没有按普通桌对待。有vip用户，无vip桌，按普通用户对待。
*/
int main()
{
  //freopen("in.txt", "r", stdin);
  int N;
  scanf("%d", &N);
  map<int, Member> ordinary, vip;	//分别表示所有用户，vip用户的map， key是用户到达时间
  for(int i = 0; i < N; i++)//读入数据
  {
    int h, m, s, d, flag;
    scanf("%d:%d:%d %d %d", &h, &m, &s, &d, &flag);	//数据按秒处理
    Member tem;
    tem.arrive_time = h*3600 + m*60 + s;
	if(d <= 120)
		tem.duration = d*60;
	else
		tem.duration = 7200;	//超过2小时按两小时
    
    ordinary.insert(make_pair(tem.arrive_time, tem));
    if(flag)
      vip.insert(make_pair(tem.arrive_time, tem));	//是vip，同时插入vip容器。
  }

  int K, M;
  scanf("%d %d", &K, &M);
  vector<Table> ta(K+1);	//为简便，从1开始
  for(int i = 0; i < M; i++)	//读入球桌的属性
  {
    int id;
    scanf("%d", &id);
    ta[id].tag = 1;
  }
  
  multimap<int, Member> result;	//存储结果，因为key是服务时间，可能相同，用multimap
  map<int, Member>::iterator it = ordinary.begin();

  while(it != ordinary.end())	//代码核心，要细心，很容易出错
  {
    if(it->second.service_time != 0)//表明该用户为vip，已处理过
    {
      it++;
      continue;
    }

	int min_vip = 1<<30;	//记录vip球桌的最小可以服务时间
	int vip_id = 0;
    int min_time = min_vip;	//所有球桌的最小可以服务时间
    int min_id = 0;
    for(int i = 1; i <= K; i++)	//分别找出所有球桌和vip球桌的最小时间
    {
      if(ta[i].start_serve < min_time)
      {
        min_time = ta[i].start_serve;
        min_id = i;
      }

	  if(ta[i].tag && ta[i].start_serve < min_vip)
	  {
		  min_vip = ta[i].start_serve;
		  vip_id = i;
	  }
    }

	map<int, Member>::iterator it_v = vip.begin();
	if(!vip.empty() && ((it_v->first >= min_vip && it_v->first == it->first)//1.表桌多人少
		|| (min_vip <= min_time &&  it_v->first < min_vip) ) )//2. 多人对一vip桌
	{	//先检查队列中是否有vip用户，且存在vip球桌，有两种情况，见上
		int time_id = it_v->first;
        if(ta[vip_id].start_serve < time_id)	//分配vip桌，更新球桌和用户的状态
          ordinary[time_id].service_time = time_id;
        else
          ordinary[time_id].service_time = ta[vip_id].start_serve;

        ta[vip_id].start_serve = ordinary[time_id].service_time + it_v->second.duration;
        if(ordinary[time_id].service_time < close_time)
          ta[vip_id].amount++;

        Member tem = ordinary[time_id];//插入结果map
        result.insert(make_pair(ordinary[time_id].service_time, tem));

        vip.erase(it_v);	//删除vip的记录，也可以不删，用指针。
      }
    else	//全部按普通用户对待
    {
      int time_id = it->first;
      if(ta[min_id].start_serve < time_id)
        it->second.service_time = time_id;
      else
        it->second.service_time = ta[min_id].start_serve;

      ta[min_id].start_serve = it->second.service_time + it->second.duration;
      if(it->second.service_time < close_time)
        ta[min_id].amount++;

	  if(!vip.empty())	//此处要判断非空
	  {
		  if(it_v->first == time_id)	//表示该用户是vip
			vip.erase(it_v);
	  }

      Member tem = it->second;
      result.insert(make_pair(it->second.service_time, tem));
      it++;
    }
    
  }
  
  multimap<int, Member>::iterator mit;//输出结果
  for(mit = result.begin(); mit != result.end(); mit++)
  {
    int t1 = mit->first;
    int t2 = mit->second.arrive_time;
    int wait = int((t1-t2)/60.0 + 0.5);	//对分钟四舍五入
    if(mit->second.service_time < close_time)
    {
      printf("%02d:%02d:%02d ", t2/3600, t2/60%60, t2%60);
      printf("%02d:%02d:%02d %d\n", t1/3600, t1/60%60, t1%60, wait);
    }
  }

  for(int i = 1; i <= K; i++)
  {
    if(i == 1)
      printf("%d", ta[i].amount);
    else
      printf(" %d", ta[i].amount);
  }
  printf("\n");

  return 0;
}

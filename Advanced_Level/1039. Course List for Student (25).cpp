#include<iostream>
#include<set>
using namespace std;

const int M = 26*26*260;//最大编号数
set<int> sst[M];//存储每个id的课程的集合
int toId(char *name);//转换成数字id

/*
题意：求学生选的课程。比较简单
思路：
由于这道题卡时间，不能用string和map.
只好把字符串id映射成数字下标啦。每个id对应一个集合，利用集合的有序性
不用再排序了
*/
int main(void)
{
  //freopen("in.txt", "r", stdin);
  int N, K;
  scanf("%d %d", &N, &K);
  

  char tem[5];
  for (int i = 0; i < K; i++)//读入数据
  {
    int id, n;
    scanf("%d %d", &id, &n);

    for (int j = 0; j < n; j++)
    {
      scanf("%s", tem);
      int na = toId(tem);
      sst[na].insert(id);
    }
  }
  
  for (int i = 0; i < N; i++)//输出
  {
    scanf("%s", tem);
    int na = toId(tem);
    if (!sst[na].empty())//集合非空
    {
      printf("%s", tem);
      printf(" %d", sst[na].size());
      set<int>::iterator it = sst[na].begin();
      for (it; it != sst[na].end(); it++)
        printf(" %d", *it);
    }
    else
      printf("%s 0", tem);
    printf("\n");
  }

  return 0;
}

int toId(char *name)//转换成数字id
{
  return ((name[0]-'A')*26*260 + (name[1]-'A')*260
    + (name[2]-'A')*10 + (name[3]-'0'));
}

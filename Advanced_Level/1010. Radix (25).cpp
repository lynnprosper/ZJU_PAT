#include<iostream>
#include<string>
using namespace std;
typedef long long int lint;

lint ToDecimal_1(lint base, string &s);	//已知进制的数转换为10进制
lint ToDecimal(lint base, string &s, lint d1);	//s2表示的数转换十进制
lint getStartRadix(string &s);	//寻找进制的下限；
lint Judge(lint d1, string &s2, lint start, lint end);	//判断两数是否相等，返回进制

/*
思路：基本逻辑题，考查细心啊。
题意是看是否存在一种进制，让两个数相等。
关键是怎么确定进制的上限和下限。显然，下限是从s2字符串中的最大字符+1开始算起，
上限是s1表示的十进制数值+1了。那么上限我们从题意无法判断，又可能很大。不能用顺序循环判断，
只有用二分法。
切记：整数类型要用 long long int;
*/
int main()
{
  //freopen("in.txt", "r", stdin);
  string s1, s2;
  lint tag, radix;
  lint d1, d2;
  cin >> s1 >>s2 >> tag>> radix;

  lint start, end, flag;	//flag是结果
  if(s1 == s2)	//这是个坑，相等的话要输出已知进制；
  {
    flag = radix;
    tag = 0;
  }
  if(tag == 1)
  {
    d1 = ToDecimal_1(radix, s1);
    start = getStartRadix(s2);	//下限
    end = (d1+1) > start ? (d1+1) : start;	//上限，
    flag = Judge(d1, s2, start, end);
  }
  else if(tag == 2)
  {
    d2 = ToDecimal_1(radix, s2);
    start = getStartRadix(s1);
    end = (d2+1) > start ? (d2+1) : start;
    flag = Judge(d2, s1, start, end);
  }

  if(flag)
    cout << flag << endl;
  else
    cout << "Impossible" <<endl;

  return 0;
}

lint ToDecimal_1(lint base, string &s)	//已知进制的数转换为10进制
{
  int i, tem;
  lint sum = 0;
  lint d = 1;
  int len = s.size();
  for(i = len-1; i >= 0; i--)
  {
    if((int)s[i] > 96)
      tem = (int)s[i] - 87;
    else
      tem = s[i] - '0';
     sum += tem * d;
	 d *= base;
  }

  return sum;
}

lint ToDecimal(lint base, string &s, lint d1)	//s2表示的数转换十进制
{
  int i, tem;
  lint sum = 0;
  lint d = 1;
  int len = s.size();
  for(i = len-1; i >= 0; i--)
  {
    if((int)s[i] > 96)
      tem = (int)s[i] - 87;
    else
      tem = s[i] - '0';

    sum += tem * d;	//注意这里的转换，我开始时用的pow()指数形式叠加，由于
    if (sum > d1)	//精度问题一直未通过，平时要注意强制转换时的精度丢失问题。
      return 1;	//这儿是剪枝优化，无需计算完，有可能超出数值表示范围。
	d *= base;
  }
  if(sum == d1)
    return 0;
  return -1;
}

lint getStartRadix(string &s)
{
  int len = s.size();
  char ch = s[0];
  for(int i = 1; i < len; i++)
  {
    if (s[i] > ch)
      ch = s[i];
  }
  if(ch >96)
    return int(ch) - 86;		//a的ascii是97；
  else
    return (ch+1 - '0');
}
lint Judge(lint d1, string &s2, lint start, lint end)
{
  lint mid;
  while(start <= end)	//二分法
  {
    mid = (start + end) /2;
    int result = ToDecimal(mid, s2, d1);

    if(result == 0)
      return mid;
    else if(result == 1)
      end = mid -1;
    else
      start = mid + 1;
  }

  return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 201;
const int MAXM = 10001;

int main()
{
  //freopen("in.txt", "r", stdin);
  int N, nn, nm;
  scanf("%d", &N);
  scanf("%d", &nn);
  int dp[MAXN][MAXM] = { 0 };
  int sa[MAXN] = { 0 };
  for (int i = 1; i <= nn; i++)
  {
    scanf("%d", &sa[i]);
  }
  scanf("%d", &nm);
  int sb[MAXM] = { 0 };
  for (int i = 1; i <= nm; i++)
  {
    scanf("%d", &sb[i]);
  }

  for (int i = 1; i <= nn; i++)
  {
    for (int j = 1; j <= nm; j++)
    {
      if (sa[i] == sb[j])
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  printf("%d\n", dp[nn][nm]);

  return 0;
}

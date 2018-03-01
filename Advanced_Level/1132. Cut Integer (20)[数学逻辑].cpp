#include <iostream>  
#include <vector>  
#include <cstring>  
#include <set>  
  
using namespace std;  
 /*
 题意：判断一个数能否被左右两部分的数的乘积整除。
思路：
数学逻辑题。
注意除数非零判断。
已AC
 */ 
int main()  
{  
    //freopen("in.txt", "r", stdin);  
    int N;  
    scanf("%d", &N);  
    char st[15];  
    uint32_t a, b, c;  
  
    for (int i = 0; i < N; i++)  
    {  
        scanf("%s", st);  
        int len = strlen(st) / 2;  
        sscanf(st, "%d", &a);  
        sscanf(st+len, "%d", &b);  
        st[len] = 0;  
        sscanf(st, "%d", &c);  
  
        if (b == 0 || c == 0)  
        {  
            printf("No\n");  
        }  
        else  
        {  
            if (a % (b*c) == 0)  
                printf("Yes\n");  
            else  
                printf("No\n");  
        }  
    }  
  
    return 0;  
}  

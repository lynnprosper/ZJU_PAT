#include <iostream>  
#include <vector>  
#include <cstring>  
#include <set>  
using namespace std;  
  
vector< vector<int> > G;    //图的邻接表表示  

/*
题意：
给出一个图，点的集合，判断图中所有边的至少一个点是否都包含在集合中。
思路：
图的遍历问题。
遍历每条边，看边的两点是否至少一点在集合里，否则输出no。
用了容器set。
*/
  
int main()  
{  
    //freopen("in.txt", "r", stdin);  
    int M, N;//边数，总点数  
    scanf("%d %d", &N, &M);  
    G.resize(N);  
  
    int s, d;  
    for (int i = 0; i < M; i++)  
    {  
        scanf("%d %d", &s, &d);  
        G[s].push_back(d);//有向图表示即可  
    }  
  
    int q, p, t, sig;//查询数， 集合的点数，临时变量，标志  
    scanf("%d", &q);  
    for (int i = 0; i < q; i++)  
    {  
        scanf("%d", &p);  
        set<int> st;  
        for (int j = 0; j < p; j++)  
        {  
            scanf("%d", &t);  
            st.insert(t);  
        }  
  
        sig = 0;  
        for (int j = 0; j < N; j++)  
        {  
            for (int k = 0; k < G[j].size(); k++)  
            {  
                if (st.count(j) == 0 && st.count(G[j][k]) == 0)//不在集合，输出no  
                {  
                    sig = 1;  
                    goto output;  
                }  
            }  
        }  
  
output: if (sig == 1)  
            printf("No\n");  
        else  
            printf("Yes\n");  
    }  
  
    return 0;  
}  

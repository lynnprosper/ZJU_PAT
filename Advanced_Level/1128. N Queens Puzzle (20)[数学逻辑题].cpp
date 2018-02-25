#include <iostream>  
#include <set>  
using namespace std;  
   
/*
题意：数学逻辑题。
给出一个序列，判断是否是国际象棋的一局。
即：任意两个棋子都不在一行、一列及斜对角线（45度）。
思路：
题目已经保证不在一列了。
接下来要判断行和对角线的情况。
行的情况，给出的序列不存在相同的，则满足。
反映在算法上，这里利用了set的性质-不存在重复的元素。
把每一个插入set里，判断set的大小即可。
对角线的情况。
这里有点小技巧，转换到直线上就简单了。
每一个棋子的位置，我们可以得出它所在的两条直线方程。
即斜率分别为1和-1的两条直线。形如y=x + a 和 x + y = b。
于是同样使用两个set，先判断set里是否有a和b，没有插入set里。
有的话，则说明不满足对角线的情况。
已AC。
*/

int main()  
{  
    //freopen("in.txt", "r", stdin);  
    int N;  
    cin >> N;  
    for (int i = 0; i < N; i++)  
    {  
        int M;  
        bool valid = true;//判断对角线的情况是否满足  
        cin >> M;  
        set<int> row, positive, negative;//分别为行、正斜率和负斜率的set  
        for (int j = 1; j <= M; j++)  
        {  
            int t;  
            cin >> t;  
            row.insert(t);  
  
            int pe = t - j;  
            int ne = t + j;  
            if (positive.count(pe) == 0)  
                positive.insert(pe);  
            else  
                valid = false;  
            if (negative.count(ne) == 0)  
                negative.insert(ne);  
            else  
                valid = false;  
        }  
  
        if (row.size() == M && valid)//都满足，成立  
            cout << "YES" << endl;  
        else  
            cout << "NO" << endl;  
    }  
  
    return 0;  
}  

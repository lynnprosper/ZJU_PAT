#include <iostream>  
#include <vector>  
#include <queue>  
using namespace std;  
  
struct Node  
{  
    Node() : left(NULL), right(NULL) {}//构造函数，使指针初始为空  
    int data;  
    Node *left, *right;  
};  
  
/*
题意：二叉树生成问题。
给出中序和后序，求出树的一定规则的层序。
思路：
中序和后序可以生成唯一的一颗二叉树。
所以先递归构造一颗二叉树。
题目不一样的地方在于层序输出时要求奇数行逆序输出。
一个思路是，我们先把每一层的结果保存到数组中，
输出的时候，奇数行逆序输出就可以了。
已AC.
*/
Node *T = NULL;//树的根指针  
int N;  
vector<int> ino, post, result[30];//分别为中序、后序序列及层序的序列  
  
void BuildTree(Node *&T, int l1, int r1, int l2, int r2);//递归构造二叉树  
int FindPos(int x);//找到某结点在中序的位置  
void DelTree(Node *root);//释放空间，考试时可忽略  
void bfs();//广度优先搜索进行层序遍历  
  
int main()  
{  
    //freopen("in.txt", "r", stdin);  
    cin >> N;  
    ino.resize(N);  
    post.resize(N);  
  
    for (int i = 0; i < N; i++)//读入数据  
        cin >> ino[i];  
    for (int i = 0; i < N; i++)  
        cin >> post[i];  
    BuildTree(T, 0, N - 1, 0, N - 1);//递归构造二叉树  
      
    bfs();//广度优先搜索进行层序遍历  
    DelTree(T);//释放空间，考试时可忽略  
  
    cout << result[0][0];//先输出第一个  
    for (int i = 1; i < 30; i++)  
    {  
        if (result[i].empty())  
            break;  
  
        if (i % 2 == 0)  
        {  
            for (int j = result[i].size() - 1; j >= 0; j--)  
            {  
                cout << ' ' << result[i][j];  
            }  
        }  
        else  
        {  
            for (int j = 0; j < result[i].size(); j++)  
            {  
                cout << ' ' << result[i][j];  
            }  
        }  
    }  
  
    return 0;  
}  
  
void BuildTree(Node *&T, int l1, int r1, int l2, int r2)//递归构造二叉树  
{  
    if (l1 > r1)  
        return;  
  
    T = new Node;  
    T->data = post[r2];  
    int rootPos = FindPos(post[r2]);  
    BuildTree(T->left, l1, rootPos - 1, l2, l2 + rootPos - l1-1);  
    BuildTree(T->right, rootPos + 1, r1, l2 + rootPos - l1, r2 - 1);  
  
    return;  
}  
  
int FindPos(int x)//找到某结点在中序的位置  
{  
    int i = 0;  
    for (i; i < N; i++)  
    {  
        if (ino[i] == x)  
            break;  
    }  
  
    return i;  
}  
  
void DelTree(Node *root)//释放空间，考试时可忽略  
{  
    if (root == NULL)  
        return;  
  
    DelTree(root->left);  
    DelTree(root->right);  
    delete root;  
    return;  
}  
  
void bfs()//广度优先搜索进行层序遍历  
{  
    queue<Node *> Q;  
    Q.push(T);  
    Node *lastone, *curOne;  
    lastone = T;//记录一层的最后一个结点  
    int level = 0;  
  
    while (!Q.empty())  
    {  
        Node *tmp = Q.front();  
        Q.pop();  
        if (tmp->left != NULL)  
        {  
            Q.push(tmp->left);  
            curOne = tmp->left;  
        }  
        if (tmp->right != NULL)  
        {  
            Q.push(tmp->right);  
            curOne = tmp->right;  
        }  
  
        result[level].push_back(tmp->data);  
        if (tmp == lastone)//遍历到了该层最后一个结点  
        {  
            lastone = curOne;  
            level++;  
        }  
    }  
  
    return;  
}  

#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 93递归实现组合型枚举
 * 相比排列最大的不同就要指定一个顺序，本题中是从小到大。
 * 从而减少个数
*/
const int N=25;
int p[N];
int st[N];
int n,m;

void print()
{
    for(int i=0;i<m;i++)printf("%d ",p[i]);
    puts("");
}

void dfs(int u)
{
    if(u==m)
    {
        print();
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            if(!u||i>p[u-1])
            {
                p[u]=i;
                st[i]=1;
                dfs(u+1);
                st[i]=0;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    dfs(0);//枚举位置
    return 0;
}
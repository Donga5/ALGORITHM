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
int n,m;

void print()
{
    for(int i=1;i<=m;i++)printf("%d ",p[i]);
    puts("");
}

void dfs(int u,int start)
{
    if(u-1+n-start+1<m)return ;//剪枝
    if(u>m)
    {
        print();
        return ;
    }
    for(int i=start;i<=n;i++)
    {
        p[u]=i;
        dfs(u+1,i+1);
    }
}
int main()
{
    cin>>n>>m;
    dfs(1,1);//枚举位置
    return 0;
}
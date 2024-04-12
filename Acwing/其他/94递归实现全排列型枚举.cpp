#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 94递归实现全排列型枚举
*/
const int N=10;
int n;
int path[N];//路径
bool st[N];//状态

void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++)
            printf("%d ",path[i]);
        puts("");
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            st[i]=true;
            path[u]=i;
            dfs(u+1);
            st[i]=false;
        }
    }
}

int main()
{
    cin>>n;
    dfs(0);

    return 0;
}
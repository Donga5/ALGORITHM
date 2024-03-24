#include<iostream>
using namespace std;

/**
 * 842.排列数字
*/
const int N=7+5;
int path[N];//存储当前的路径
bool st[N];//存储每个数字的状态
int n;

void dfs(int u)
{
    if(u==n)
    {
        //到达了最后
        for(int i=0;i<n;i++)
            printf("%d ",path[i]);
        puts("");
        return ;
    }

    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            path[u]=i;
            st[i]=true;
            dfs(u+1);
            st[i]=false;//回溯，恢复现场
        }
    }
}

int main()
{
    cin>>n;
    dfs(0);
    return 0;
}
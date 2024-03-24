#include<iostream>
using namespace std;
/**
 * n-皇后问题
 * 第一种搜索:按照全排列方式
*/

const int N=10;

bool cols[N],dg[2*N],udg[2*N];//每一列状态，正对角线，反对角线
char g[N][N];//存储皇后排列

int n;

void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++)puts(g[i]);
        puts("");    
        return ;
    }

    //从第0列开始枚举
    for(int i=0;i<n;i++)
    {
        if(!cols[i]&&!dg[n-u+i]&&!udg[u+i])//这里+n是为了保证下标不是负数
        {
            //标记当前状态
            g[u][i]='Q';
            cols[i]=dg[n-u+i]=udg[u+i]=true;
            dfs(u+1);
            //回溯
            cols[i]=dg[n-u+i]=udg[u+i]=false;
            g[u][i]='.';
        }
    }

}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j]='.';
    dfs(0);
    return 0;
}
#include<iostream>
using namespace std;

/**
 * n-皇后问题
 * 按照每个格子来进行搜索，这样的话每次递归的时候需要传递当前皇后的数量
*/
const int N=10;
bool rows[N],cols[N],dg[N*2],udg[N*2];
int n;
char g[N][N];


void dfs(int x,int y,int count)
{
    if(y>=n)y=0,x++;//到达右边界，切换到下一行
    if(x==n)
    {
        if(count==n)
        {
            for(int i=0;i<n;i++)puts(g[i]);
            puts("");
        }
        return ;
    }

    //当前格子不放
    dfs(x,y+1,count);//注意！！！这里不能使用y++
    
    //放
    if(!rows[x]&&!cols[y]&&!dg[n-x+y]&&!udg[x+y])
    {
        g[x][y]='Q';
        rows[x]=cols[y]=dg[n-x+y]=udg[x+y]=true;
        dfs(x,y+1,count+1);
        g[x][y]='.';
        rows[x]=cols[y]=dg[n-x+y]=udg[x+y]=false;
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j]='.';
    dfs(0,0,0);
    return 0;
}
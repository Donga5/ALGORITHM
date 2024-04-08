#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

/**
 * 2060奶牛选美
 * flood fill dfs
*/
#define x first
#define y second
typedef pair<int,int>PIT;
const int N=55;
int n,m;
char g[N][N];
vector<PIT> points[2];//存储两个联通块中的点

int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

void dfs(int a,int b,vector<PIT>& q)
{
    g[a][b]='.';
    q.push_back({a,b});

    for(int i=0;i<4;i++)
    {
        int xx=a+dx[i],yy=b+dy[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<m&&g[xx][yy]=='X')
            dfs(xx,yy,q);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)scanf("%s",g[i]); //使用字符串的方式来进行处理

    int k=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j]=='X')
                dfs(i,j,points[k++]);//一次dfs能够找到一个联通块

    int res=1e8;
    for(auto &a:points[0])
        for(auto &b:points[1])
        {
            res=min(res,abs(a.x-b.x)+abs(a.y-b.y));
        }
    cout<<res-1<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
/**
 * 1097池塘计数
 * flood fill
 * bfs
 * 使用模拟队列
*/
const int N=1010,M=N*N;
typedef pair<int,int> PIT;
PIT q[M];//队列
int n,m;
char g[N][N];//地图
bool st[N][N];//状态

void bfs(int x,int y)
{
    int hh=0,tt=0;
    q[0]={x,y};
    st[x][y]=true;
    while(hh<=tt)
    {
        auto t=q[hh++];
        // st[t.first][t.second]=1;
        //八连通，直接枚举3*3矩阵，并且去掉中心点
        for(int i=t.first-1;i<=t.first+1;i++)
            for(int j=t.second-1;j<=t.second+1;j++)
            {
                if(i==t.first&&j==t.second)continue;
                if(i<0||i>=n||j<0||j>=m)continue;
                if(g[i][j]=='.'||st[i][j])continue;
                q[++tt]={i,j};   
                st[i][j]=1;//必须先在这里进行标记,不然会导致重复添加
            }
    }   
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)scanf("%s",g[i]);

    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j]=='W'&&!st[i][j])
                {
                    bfs(i,j);
                    cnt++;
                }
    cout<<cnt<<endl;
    return 0;
}
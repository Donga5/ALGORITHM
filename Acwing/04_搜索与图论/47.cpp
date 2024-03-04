#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

/**
 * 844走迷宫
 * 使用stl queue
*/
typedef pair<int,int> PIT;
queue<PIT> q;
const int N=110;
int g[N][N],d[N][N];//地图，以及到起点的距离
int n,m;

int bfs()
{
    memset(d,-1,sizeof d);
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
    q.push({0,0});

    while(!q.empty())
    {
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;++i)
        {
            int x=t.first+dx[i],y=t.second+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&d[x][y]==-1&&g[x][y]==0)
            {
                q.push({x,y});
                d[x][y]=d[t.first][t.second]+1;
            }
        }
    }

    return d[n-1][m-1];

}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&g[i][j]);
    cout<<bfs()+1<<endl;

    return 0;
}
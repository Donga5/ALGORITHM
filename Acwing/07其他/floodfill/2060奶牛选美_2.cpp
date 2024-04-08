#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
/**
 * 2060奶牛选美
 * flood fill 
*/
const int N=55;
typedef pair<int,int> PIT;
int n,m;
char g[N][N];
vector<PIT>points[2];

int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

void bfs(int x,int y,vector<PIT>&point)
{
    queue<PIT> q;
    q.push({x,y});
    while(!q.empty())
    {
        auto t=q.front();
        q.pop();
        //应该放到.qpush那里进行，这样不会导致重复添加。
        //在数据量打的时候会爆掉内存
        g[t.first][t.second]='.';//直接修改，而没有使用单独记录每个点的状态
        point.push_back(t);
        for(int i=0;i<4;i++)
        {
            int xx=t.first+dx[i],yy=t.second+dy[i];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&g[xx][yy]=='X')
            {
                q.push({xx,yy});
            }
        }
    }
}


int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)scanf("%s",g[i]);

    int k=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j]=='X')
                bfs(i,j,points[k++]);

    // printf("%d %d\n",points[0].size(),points[1].size());

    int res=110;
    for(auto a:points[0])
        for(auto b:points[1])
            res=min(res,abs(a.first-b.first)+abs(a.second-b.second));
    cout<<res-1<<endl;
    return 0;
}
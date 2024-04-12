#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

/**
 * 1098城堡问题
 * bfs flood fill
 * 注意方向，这里的dx和dy不能随便写,
*/
#define x first
#define y second
typedef pair<int,int> PIT;
const int N=55;
int g[N][N];
int n,m;
bool st[N][N];

int dy[4]={-1,0,1,0},dx[4]={0,-1,0,1};

int bfs(int a,int b)
{
    int cnt=0;
    queue<PIT>q;
    q.push({a,b});
    st[a][b]=true;
    while(q.size())
    {
        auto t=q.front();
        q.pop();
        cnt++;
        
        for(int i=0;i<=3;i++)
        {
            if(!(g[t.x][t.y]>>i&1))
            {
                int xx=t.x+dx[i],yy=t.y+dy[i];
                if(xx>=0&&xx<n&&yy>=0&&yy<m&&!st[xx][yy])
                {
                    q.push({xx,yy});
                    st[xx][yy]=1;
                }
            }
        }        

    }
    return cnt;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)   
            scanf("%d",&g[i][j]);

    int cnt=0;
    int res=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!st[i][j])
            {
                res=max(res,bfs(i,j));
                cnt++;
            }
    cout<<cnt<<endl;
    cout<<res<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
/**
 * 1233全球变暖
*/
#define x first
#define y second
typedef pair<int,int> PIT;
const int N=1010;
int n;
char g[N][N];
bool st[N][N];

int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

bool bfs(int a,int b)
{
    queue<PIT>q;
    q.push({a,b});
    st[a][b]=1;
    vector<PIT>arr;

    int round=0;
    while(q.size())
    {
        auto t=q.front();
        q.pop();
        arr.push_back(t);
        for(int i=0;i<4;i++)
        {
            int xx=t.x+dx[i],yy=t.y+dy[i];
            if(xx<0||xx>=n||yy<0||yy>=n)continue;
            if(st[xx][yy]||g[xx][yy]=='.')continue;
            q.push({xx,yy});
            st[xx][yy]=1;
        }
    }
    for(auto t:arr)
    {
        for(int i=0;i<4;i++)
        {
            int xx=t.x+dx[i],yy=t.y+dy[i];
            if(xx<0||xx>=n||yy<0||yy>=n)continue;
            if(g[xx][yy]=='.')
            {
                round++;
                break;
            }
        }
    }
    return round==arr.size();

}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)scanf("%s",g[i]);
    
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(!st[i][j]&&g[i][j]=='#')
            {
                if(bfs(i,j))cnt++;
            }
    cout<<cnt<<endl;
    return 0;
}
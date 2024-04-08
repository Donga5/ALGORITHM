#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;

/**
 * 1106山峰和山谷
 * flood fill
*/
#define x first
#define y second
const int N=1e3+10;
typedef long long LL;
typedef pair<int,int> PIT;
int n;
int g[N][N];
bool st[N][N];

void bfs(int a,int b,bool &is_c1,bool &is_c2)
{
    queue<PIT>q;
    q.push({a,b});
    st[a][b]=1;

    int high=0,low=0;
    while(q.size())
    {
        auto t=q.front();
        q.pop();
        for(int i=t.x-1;i<=t.x+1;i++)
            for(int j=t.y-1;j<=t.y+1;j++)
            {
                if(t.x==i&&t.y==j)continue;
                if(i<0||i>=n||j<0||j>=n)continue;
                if(!st[i][j]&&g[i][j]==g[t.x][t.y])
                {
                    q.push({i,j});
                    st[i][j]=1;
                    continue;
                }
                //高度不相同，就不在当前联通块当中了
                if(g[i][j]>g[t.x][t.y])high++;   
                if(g[i][j]<g[t.x][t.y])low++;
            }
    }
    if(high==0)is_c1=true;
    if(low==0)is_c2=true;

}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&g[i][j]);
    
    int c1=0,c2=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(!st[i][j])
            {
                bool is_c1=false,is_c2=false;
                bfs(i,j,is_c1,is_c2);
                if(is_c1)c1++;
                if(is_c2)c2++;
            }
        }
    cout<<c1<<" "<<c2<<endl;
    return 0;
}

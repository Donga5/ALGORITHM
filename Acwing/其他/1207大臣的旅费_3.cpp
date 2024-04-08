#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

/**
 * 1207大臣的旅费
 * 做法二
*/
typedef long long LL;
const int N=1e5+10;
struct Node
{
    int id,w;
};
vector<Node>h[N];
int dis[N];
int n;

void dfs(int u,int father,int dist)//有father这个参数为了保证不往回走
{
    dis[u]=dist;
    for(auto t:h[u])
    {
        if(father!=t.id)
            dfs(t.id,u,max(dist,dist+t.w));
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        h[a].push_back({b,c});
        h[b].push_back({a,c});
    }

    dfs(1,-1,0);
    int u=1;
    for(int i=1;i<=n;i++)
        if(dis[i]>dis[u])u=i;
    dfs(u,-1,0);
    for(int i=1;i<=n;i++)
        if(dis[i]>dis[u])u=i;

    int maxv=dis[u];
    
    printf("%lld\n",(LL)maxv*10+(LL)maxv*(maxv+1)/2);

    return 0;
}
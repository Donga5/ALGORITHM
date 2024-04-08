#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

/**
 * 1207大臣的旅费
 * 树的直径:树中最远两个点之间的距离
 * 
*/
const int N=1e5+10;
typedef long long LL;

struct Node
{
    int id,w;
};
vector<Node> h[N];
bool vis[N];
int n;
int remote_node=0;
int max_dist=-1;

void dfs(int u,int dist)
{
    vis[u]=true;
    for(int i=0;i<h[u].size();i++)
    {
        int t=h[u][i].id;
        int w=h[u][i].w;
        if(!vis[t])
        {
            if(dist+w>max_dist)
            {
                max_dist=dist+w;
                remote_node=t;
            }
            dfs(t,dist+w);
        }
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
    dfs(1,0);
    max_dist=-1;
    memset(vis,false,sizeof(vis));
    dfs(remote_node,0);
    cout<<((LL)max_dist*10+(LL)max_dist*(1+max_dist)/2)<<endl;
    return 0;
}
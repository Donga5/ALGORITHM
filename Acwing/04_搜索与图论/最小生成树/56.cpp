#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

/**
 *  858 Prim求最小生成树
*/
const int N=510,M=1e5+10,INF=0x3f3f3f3f;
int g[N][N];
int dist[N];//表示该点到联通块中点的距离
bool st[N];//表示已经在联通块中的点
int n,m;

int prim()
{
    memset(dist,0x3f,sizeof(dist));
    int res=0;
    for(int i=0;i<n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
                t=j;
        }

        if(i&&dist[t]==INF)
        {
            return INF;
        }
        
        st[t]=true;
        
        if(i)res+=dist[t];//第一次选择初始点的时候不用更新
        //更新
        for(int j=1;j<=n;j++)dist[j]=min(dist[j],g[t][j]);
    }
    return res;
}

int main()
{
    memset(g,0x3f,sizeof(g));
    cin>>n>>m;
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=g[b][a]=min(g[a][b],c);
    }

    int t=prim();
    if(t==INF)puts("impossible");
    else cout<<t<<endl;


    return 0;
}
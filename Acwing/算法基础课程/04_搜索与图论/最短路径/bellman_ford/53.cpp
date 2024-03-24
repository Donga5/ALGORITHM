#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

/**
 * 853.有边数限制的最短路
 * bellman_ford 算法
*/
const int N=500+10,M=1e4+10,INF=0x3f3f3f3f;
struct Edge
{
    int a,b,w;
}edges[M];
int n,m,k;
int dist[N],last[N];


void bellman_ford()
{
    //初始化
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;

    for(int i=0;i<k;i++)
    {
        memcpy(last,dist,sizeof(dist));

        for(int j=0;j<m;j++)
        {
            auto e=edges[j];//枚举所有边
            dist[e.b]=min(dist[e.b],last[e.a]+e.w);//防止出现“串联”，使用上一次遍历的结果来进行更新
        }
    }

    if(dist[n]> INF/2)puts("impossible");//如果在k步没有到达，并且中间路径上存在负权值的环，可能会导致计算得到值小于INF,但是由于k的
                                        //限制，其实实际得到disn[n]也不会太少，所以使用>INF/2来判断，而不能使用==INF判断
    else
        cout<<dist[n]<<endl;

}

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<m;++i)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edges[i]={a,b,w};
    }

    bellman_ford();

    return 0;
}
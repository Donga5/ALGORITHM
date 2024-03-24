#include<iostream>
#include<algorithm>
using namespace std;
/*
    859 kruskal 求最小生成树
*/
struct Edge
{
    int a,b,w;
    //从小到大排序重载小于号
    bool const operator< (const Edge &e)const 
    {
        return w<e.w;
    }
};
const int N=1e5+10,M=2e5+10;
Edge edges[M];
int p[N];

int find(int x)
{
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)p[i]=i;

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edges[i]={a,b,c};
    }

    //kruscal
    sort(edges,edges+m);

    int res=0,cnt=0;//统计权值数和边数
    for(int i=0;i<m;i++)
    {
        int a=edges[i].a,b=edges[i].b;
        a=find(a),b=find(b);
        if(a!=b)
        {
            p[a]=b;
            res+=edges[i].w;
            cnt++;
        }
    }

    if(cnt<n-1)puts("impossible");//通过边数判断是否全部都连通
    else cout<<res<<endl;
    return 0;
}
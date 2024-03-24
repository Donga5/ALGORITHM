#include<iostream>
#include<cstring>
using namespace std;


/**
 * 848 有向图的拓扑排序
 * 基本思路：
 * 在添加边的时候，记录每个点的入度，
 * 初始的时候将所有入度为0的点添加到队列中，进行BFS。对于每个入度为0的点，枚举相连的点，如果去掉之后，
 * 该点入度为0，则可以添加到队列当中
*/
const int N=1e5+10;
int h[N],e[N],ne[N],idx;
int d[N],q[N];//d表示入度
int n,m;


void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool topsort()
{
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++)
        if(!d[i])
            q[++tt]=i;
    
    while(hh<=tt)
    {
        int t=q[hh++];//t是节点编号
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            d[j]--;
            if(d[j]==0)
            {
                q[++tt]=j;
            }
        }
    }
    return tt==n-1;
}

int main()
{
    memset(h,-1,sizeof h);
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        d[b]++;
    }

    if(topsort())
    {
        for(int i=0;i<n;i++)
        {
            printf("%d ",q[i]);
        }
        puts("");
    }
    else{
        puts("-1");
    }
    
    return 0;
}
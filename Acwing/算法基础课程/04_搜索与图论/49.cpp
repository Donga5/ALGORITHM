#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

/**
 * 847图中点的层次
 * BFS，使用BFS的框架，使用邻接表来存储图
  * 
*/
const int N=1e5+10;
int n,m;

int h[N],e[N],ne[N],idx;
int d[N],q[N];

int bfs(int u)
{
    int hh=0,tt=-1;
    q[++tt]=1;
    d[1]=0;
    while(hh<=tt)
    {
        int t=q[hh++];
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(d[j]==-1)
            {
                q[++tt]=j;
                d[j]=d[t]+1;
            }
        }
    }

    return d[n];
}

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int main()
{
    memset(h,-1,sizeof h);
    memset(d,-1,sizeof d);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }

    cout<<bfs(1)<<endl;
    return 0;
}
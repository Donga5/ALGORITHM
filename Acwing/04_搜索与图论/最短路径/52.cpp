#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

/**
 * 850 Dijkstra算法求最短路II
 * 实现方法：
 * 利用stl堆存储距离，使得每次取得最小值的操作时间复杂度降低为O(1)
*/
typedef pair<int,int> PIT;
const int N=1e6+10,INF=0x3f3f3f3f;
int n,m;
int h[N],w[N],e[N],ne[N],idx;//稀疏图，使用邻接表来存储
bool st[N];
int dist[N];

void add(int a,int b,int d)
{
    e[idx]=b,w[idx]=d,ne[idx]=h[a],h[a]=idx++;
}

int dijkstra()
{
    memset(dist,0x3f,sizeof(dist));
    priority_queue<PIT,vector<PIT>,greater<PIT>>q;//堆
    q.push({0,1});//把到一号点的距离存储为0
    dist[1]=0;//这个一定得记得

    while(q.size())
    {
        auto t=q.top();
        q.pop();

        int ver=t.second,distance=t.first;

        if(st[ver])
        {
            continue;//可能会出现冗余存储,如果已经存在了最小值，则跳过
        }

        st[ver]=true;

        for(int i=h[ver];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[ver]+w[i])
            {
                dist[j]=dist[ver]+w[i];
                q.push({dist[j],j});//将新更新的距离存储到队列中，有可能dist[j]没有进行更新，就会出现冗余存储
            }
        }
    }
    if(dist[n]==INF)
    {
        return -1;
    }
    return dist[n];
    
}

int main()
{
    memset(h,-1,sizeof(h));
    cin>>n>>m;

    while(m--)
    {
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        add(a,b,d);
    }

    cout<<dijkstra();

    return 0;  
}
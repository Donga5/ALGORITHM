#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

/**
 * 851 spfa求最短路径(不存在负环)
 * spfa(short path fast algorithm)
 * 每次利用刚刚更新过的点(使用队列来进行维护），来去更新所有的出边。
*/
const int N=1e5+10,INF=0x3f3f3f3f;
int h[N],e[N],ne[N],w[N],idx;
int n,m;
int dist[N];
int st[N];//记录某个点是否已经在队列中


void add(int a,int b, int z)
{
    e[idx]=b,ne[idx]=h[a],w[idx]=z,h[a]=idx++;
}

void spfa()
{
    memset(dist,0x3f,sizeof(dist));//注意dist和h的初始化顺序
    
    dist[1]=0;
    
    queue<int>q;
    q.push(1);
    st[1]=true;

    while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=false;//重新进行标记没有被更新过

        //更新以t的出边的所有点
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[t]+w[i]<dist[j])
            {
                dist[j]=dist[t]+w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    if(dist[n]==INF)cout<<"impossible";
    else
        cout<<dist[n]<<endl;

}

int main()
{
    memset(h,-1,sizeof(h));
    cin>>n>>m;
    int t=m;
    while(t--)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        add(a,b,w);
    }
    spfa();
    return 0;
}
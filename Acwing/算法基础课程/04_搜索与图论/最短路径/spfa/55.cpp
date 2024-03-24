#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;

/**
 * 852.spfa判断负环
 * 算法理解：
 * 1.本次因为是只求负环，所以不需要进行初始化。
 * 2.dist数组更新的时候就是遇到负边的时候进行更新
 * 3.利用cnt数组记录当前走的步数，当超过n的时候，则必定点数已经超过了n,说明是有环
 * 4.如果有负环意味着spfa会在负环上跑无限次，因为每次循环一次都会是dt减少，所以dt根本不是记录最短路径的，他的初值多少也无所谓
 * 
*/
const int N=2010,M=1e4+10,INF=0x3f3f3f3f;
int h[N],e[M],ne[M],w[M],idx;
int dist[N],cnt[N];
int st[N];//记录节点是否在队列当中
int n,m;

void add(int a,int b,int c)
{
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}

bool spfa()
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        st[i]=true;
        q.push(i);
    }  

    while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=false;
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[t]+w[i])
            {
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=n)
                    return true;
                dist[j]=dist[t]+w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    return false;

}


int main()
{
    memset(h,-1,sizeof(h));
    cin>>n>>m;
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }

    if(spfa())
        puts("Yes");
    else
        puts("No");

    return 0;
}
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
/**
 * 1207大臣的旅费
 * 使用自定义链表来进行实现
 * 现在还没有发现问题，通过为8/12
*/
typedef long long LL;
const int N=1e5+10;
int n;
int e[N],h[N],ne[N],w[N],idx;

bool vis[N];
int maxv=-1;
int num=0;//树的直径的端点编号


void add(int a,int b,int c)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx,w[idx]=c,idx++;
}

void dfs(int u,int dist)
{
    vis[u]=true;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int t=e[i];
        if(!vis[t])
        {
            if(dist+w[i]>maxv)
            {
                maxv=dist+w[i];
                num=t;
            }
            dfs(t,dist+w[i]);
        }
    }
}



int main()
{
    memset(h,-1,sizeof(h));
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,0);//找到树的直径的一段
    maxv=-1;
    memset(vis,false,sizeof(vis));
    dfs(num,0);
    cout<<((LL)maxv*10+(LL)maxv*(maxv+1)/2)<<endl;

    return 0;
}
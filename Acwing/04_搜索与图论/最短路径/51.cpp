#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

/**
 *849 Dijkstra算法I
 这里要注意数值,最多有10^5条边，每条边长度不超过10^5,所以最远距离不超过10^10
 算法思想：
 每次找到没有确定最小值的点t，然后说用它来更新到其他点的距离 
  
*/
const int N=510,INF=0x3f3f3f3f;//无穷值,

int g[N][N];
int dist[N];
int st[N];
int n,m;


int dijkstra()
{
    memset(dist,0x3f,sizeof(dist));
    
    dist[1]=0;//这里一定要记得,不然dist数组不能进行初始化

    for(int i=0;i<n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
                t=j;
        st[t]=true;
        for(int j=1;j<=n;j++)
        {
            dist[j]=min(dist[j],dist[t]+g[t][j]);
        }
    }

    if(dist[n]==INF)
        return -1;
    else 
        return dist[n];
}

int main()
{
    cin>>n>>m;

    memset(g,0x3f,sizeof(g)); 

    while(m--)
    {
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        g[a][b]=min(g[a][b],d); 
    }

    cout<<dijkstra();
    
    return 0;
}
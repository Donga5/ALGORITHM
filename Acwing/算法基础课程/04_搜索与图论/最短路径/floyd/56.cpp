#include<iostream>
#include<algorithm>

using namespace std;

/**
 * 854 Floyd算法求最短路
 * 具体的算法原理还没有弄清楚，等学了动态规划那部分再来搞
*/

const int N=210;
int d[N][N],INF=1e9;
int n,m,k;

void floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main()
{                                                                                                                                                           
      cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j)d[i][j]=0;//取消掉了自环
            else d[i][j]=INF;
    
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        d[a][b]=min(d[a][b],c);//存在多条边，去最小的那条
    }
    
    floyd();

    while(k--)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        if(d[a][b]>INF/2)cout<<"impossible"<<endl;//可能有负边导致最后无法到达，而且距离比INF小
        else printf("%d\n",d[a][b]);
    }
    return 0;
}
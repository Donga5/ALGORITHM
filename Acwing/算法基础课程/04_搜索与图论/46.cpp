#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/**
 * 844走迷宫
 * 手动实现队列
 *
*/

typedef pair<int,int> PIT;
int n,m;
const int N=110;

int g[N][N];
int st[N][N];//表                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     示距离
int hh=0,tt=-1;//对头和队尾元素
PIT q[N*N];//队列
PIT pre[N][N];


int bfs()
{
    
    memset(st,-1,sizeof st); 
    //四个方向
    int x[4]={-1,0,1,0},y[4]={0,1,0,-1};//这里命名的时候使用dx,dy更加合适一些
    //将初始点入队
    q[++tt]={0,0};

    while(hh<=tt)
    {
        PIT t=q[hh++];//弹出队头
        for(int i=0;i<4;i++)
        {
            int x1=t.first+x[i],y1=t.second+y[i];
            if(x1>=0&&y1>=0&&x1<n&&y1<m&&g[x1][y1]==0&&st[x1][y1]==-1)
            {   
                pre[x1][y1]=t;
                st[x1][y1]=st[t.first][t.second]+1;
                q[++tt]={x1,y1};
            }
        }
    }

    //输出路径
    // int x2=n-1,y2=m-1;
    // while(x2||y2)
    // {
    //     printf("%d %d\n",x2,y2);
    //     auto t=pre[x2][y2];
    //     x2=t.first;
    //     y2=t.second;
    // }
    // puts("0 0");

    return st[n-1][m-1];
}



int main()
{
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>g[i][j];
    }

    cout<<bfs()+1<<endl;//因为距离是从0开始算的

    return 0;
}
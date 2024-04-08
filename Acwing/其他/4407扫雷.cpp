#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
/**
 * 4407扫雷
 * dfs,哈希，
 * 基本思路:
 * 1.利用进制进行特征降维
 * 2.哈希映射
 * 3.id数组处理相同位置有多个点情况
 * 4.
 * 
 * 易错点注意：这里的下标不能从0开始
 * id数组被用来存储每个位置最大半径的地雷的编号。然而，由于地雷的编号从0开始，所以当id[key]为0时，可能表示这个位置的地雷编号就是0，也可能表示这个位置没有地雷。这就导致了一个问题：
 * 在检查一个位置是否有地雷时，如果id[key]为0，我们无法确定这是因为这个位置的地雷
*/
typedef long long ll;
const int N=5e4+10,M=1e6+7,X=1e9+1;
ll h[M];//哈希表
int n,m;

bool st[N];//每个点的状态
int id[M],res=0;//id用来处理同一个坐标可能有多个地雷的情况,标记当前位置半径最大的炸弹编号

struct Node
{
    int x,y,r;
}b[N];//存储所有的点


ll get(int x,int y)
{
    //利用x进制降维，方便进行哈希映射,其中X必须在数值范围之外，才能保证每个转换出来的数字都不相同
    return (ll)x*X+y; 
}

bool check(int x1,int y1,int r,int x2,int y2)
{
    int d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    return d<=r*r;
}

int find(int x,int y)
{
    ll t=get(x,y);
    int key=(t%M+M)%M;//开放地址法处理冲突
    while(h[key]!=-1&&h[key]!=t)
    {
        key++;
        if(key==M)key=0;     
    }
    return key;
}

void bfs(int pos)
{
    queue<int>q;
    q.push(pos);
    st[pos]=true;
    while(q.size())
    {
        int t=q.front();
        q.pop();
        int x=b[t].x,y=b[t].y,r=b[t].r;
        for(int i=x-r;i<=x+r;i++)
        {
            for(int j=y-r;j<=y+r;j++)
            {
                int key=find(i,j);
                if(id[key]&&!st[id[key]]&&check(x,y,r,i,j))
                {
                    int p=id[key];
                    st[p]=true;
                    q.push(p);
                }
            }
        }
    }
}

int main()
{
    memset(h,-1,sizeof(h));

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x,y,r;
        scanf("%d%d%d",&x,&y,&r);
        b[i]={x,y,r};
        int key=find(x,y);
        if(h[key]==-1)h[key]=get(x,y);//放到哈希表当中

        //标记当前点半径最大的点的下标
        if(!id[key]||b[id[key]].r<r)id[key]=i;
    }

    //枚举每个导弹的位置
    for(int i=1;i<=m;i++)
    {
        int x,y,r;
        scanf("%d%d%d",&x,&y,&r);
        for(int i=x-r;i<=x+r;i++)
        {
            for(int j=y-r;j<=y+r;j++)
            {
                int key=find(i,j);
                if(id[key]&&!st[id[key]]&&check(x,y,r,i,j))bfs(id[key]);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        int key=find(b[i].x,b[i].y);
        int pos=id[key];
        if(pos&&st[pos])res++;
    }

    cout<<res<<endl;
    return 0;
}
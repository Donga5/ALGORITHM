#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

/**
 * 1264动态求连续区间和_树状数组写法
*/
const int N=1e6+10;
struct Edge
{
    int l,r;
    int sum;
}tr[N*4];
int a[N];
int n,m;

void pushup(int u)
{
    //利用子节点的信息，来计算当前节点的和
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void build(int u,int l,int r)
{
    if(l==r)tr[u]={l,r,a[r]};
    else
    {
        tr[u]={l,r,0};
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);//计算当前节点的值
    }
}

int query(int u,int l,int r)
{
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].sum;
    int mid=(tr[u].l+tr[u].r)/2;
    int s=0;
    if(l<=mid)s+=query(u<<1,l,r);//这里没有想清楚为什么不是l,mid
    if(r>=mid+1)s+=query(u<<1|1,l,r);
    return s;
}
void modify(int u,int x,int v)
{
    if(tr[u].l==tr[u].r)tr[u].sum+=v;
    else
    {
        int mid=(tr[u].r+tr[u].l)>>1;
        if(x<=mid)modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}


int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,1,n);

    while(m--)
    {
        int k,x,y;
        scanf("%d%d%d",&k,&x,&y);
        if(k==0)cout<<query(1,x,y)<<endl;
        else modify(1,x,y);
    }

    return 0;
}
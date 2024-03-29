#include<iostream>
#include<algorithm>
#include<cstdio>
#include<climits>
using namespace std;

/**
 * 1270数组区间的最大值
*/
const int N=1e5+10;
int a[N];
int INF=2147483647;
struct Range
{
    int l,r;
    int m;
}tr[4*N];
int n,m;

void pushup(int u)
{
    //当子节点的值来更新当前节点
    tr[u].m=max(tr[u<<1].m,tr[u<<1|1].m);
}

void build(int u,int l,int r)
{
    tr[u]={l,r,0};//初始化
    if(l==r)tr[u].m=a[r];
    else{
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

int query(int u,int l,int r)
{
    if(l<=tr[u].l&&tr[u].r<=r)return tr[u].m;
    else
    {
        int s=INT_MIN;
        int mid=tr[u].l+tr[u].r>>1;
        if(l<=mid)s=max(s,query(u<<1,l,r));
        if(r>=mid+1)s=max(s,query(u<<1|1,l,r));
        return s;
    }
    
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,1,n);

    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",query(1,l,r));
    }

    return 0;
}
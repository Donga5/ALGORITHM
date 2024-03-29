#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

/**
 * 1264. 动态求连续区间和
*/
const int N=1e6+10;
int a[N],tr[N];
int n,m;

int lowbit(int x)
{
    return x&-x;
}

int query(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=tr[i];
    return res;
}
void add(int x,int v)
{
    for(int i=x;i<=n;i+=lowbit(i))tr[i]+=v;
}


int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    //树状数组初始化
    for(int i=1;i<=n;i++)add(i,a[i]);
    while(m--)
    {
        int k,x,y;
        scanf("%d%d%d",&k,&x,&y);
        if(k==0)printf("%d\n",query(y)-query(x-1));
        else add(x,y);
    }
    return 0;
}
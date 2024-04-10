#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/**
 * 242一个简单的整数问题
 * 将差分数组添加到数状数组里边去
 * 区间修改
 * 单点求和
*/
typedef long long LL;
const int N=1e5+10;
int n,m;
int w[N];
LL tr[N];

int lowbit(int x)
{
    return x&-x;
}

LL query(int x)
{
    LL res=0;
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
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);

    for(int i=n;i;i--)add(i,w[i]-w[i-1]);

    char op[2];
    while(m--)
    {
        char op[2];
        int l,r,d;
        scanf("%s%d",op,&l);
        if(op[0]=='C')
        {
            scanf("%d%d",&r,&d);
            add(l,d),add(r+1,-d);
        }
        else 
        {
            printf("%lld\n",query(l));
        }
    }

    return 0;
}
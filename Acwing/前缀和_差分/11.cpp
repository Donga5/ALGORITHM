#include<iostream>
using namespace std;

const int N=1e6+10;
int a[N],b[N];

void insert(int l,int r,int c)
{
    b[l]+=c;
    b[r+1]-=c;
}
int main()
{
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    /**
     * 构造差分数组
     * 将a看作是初始都为0的数组，
     * b也是初始为0的数组,可以看作是n次的加c操作
    */
    for(int i=1;i<=n;i++)insert(i,i,a[i]);
    while(m--)
    {
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        insert(l,r,c);
    }
    
    for(int i=1;i<=n;i++)b[i]+=b[i-1];
    for(int i=1;i<=n;i++)printf("%d ",b[i]);
    return 0;
}
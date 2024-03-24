#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 4656技能升级
 * 基本思路:
 * 1.使用二分和等差数列公式来找到前m大的值
 * 2.然后利用等差数列性质求出这些数的和
*/
typedef long long LL;
const int N=1e5+10;
int a[N],b[N];
int n,m;

bool check(int x)
{
    LL cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=x)
        {
            cnt+=(a[i]-x)/b[i]+1;
        }
        if(cnt>=m)return true;
    }
    if(cnt>=m)return true;
    else return false;
}



int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);

    int l=0,r=1e6;
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }

    LL res=0,cnt=0;//注意这里的数据范围
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=r)
        {
            int t=(a[i]-r)/b[i]+1;
            cnt+=t;
            res+=(LL)t*(a[i]+a[i]-(t-1)*b[i])/2;
        }
    }
    cout<<(res-(cnt-m)*r)<<endl;//减去重复项
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 1236递增三元组
 * 二分写法，时间复杂度较高一点
 * 
*/
const int N=1e5+10;
int a[N],b[N],c[N];
int n;
typedef long long LL;
int main()
{

    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    sort(c+1,c+n+1);

    LL res=0;
    for(int i=1;i<=n;i++)
    {
        LL p,q;//p表示a中符合个数的点
        int t=b[i];
        int l=1,r=n;
        while(l<r)
        {
            int mid=l+r>>1;
            if(a[mid]<t)l=mid+1;
            else r=mid;
        }
        if(a[r]>=t)p=r-1;
        else p=n;

        l=1,r=n;
        while(l<r)
        {
            int mid=l+r+1>>1;
            if(c[mid]>t)r=mid-1;
            else l=mid;
        }

        if(c[r]<=t)q=n-r;
        else q=n;

        res+=(LL)q*p;
    }
    cout<<res<<endl;
    return 0;
}
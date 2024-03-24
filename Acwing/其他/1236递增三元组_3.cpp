#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 1236递增三元组
 * 双指针写法，时间复杂度为o(n)
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
    int p=1,q=1;
    for(int i=1;i<=n;i++)
    {
       int t=b[i];
       while(a[p]<t&&p<=n)p++;
       while(c[q]<=t&&q<=n)q++;
       res+=(LL)(p-1)*(n-q+1);
       
    }
    cout<<res<<endl;
    return 0;
}
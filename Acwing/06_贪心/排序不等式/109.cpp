#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 913 排队打水
*/
typedef long long LL;
int n;
const int N=1e5+10;
int a[N];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);

    sort(a,a+n);
    LL res=0;
    for(int i=0;i<n;i++)res+=a[i]*(n-1-i);

    cout<<res<<endl;
    
    return 0;
}
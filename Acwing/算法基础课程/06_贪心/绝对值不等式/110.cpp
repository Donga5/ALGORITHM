#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 104货仓选址
 * sort排序的时候一定要注意
 * 这个题如果是下标从1开始一定要n/2上取整，也就是(n+1)/2下去整
*/
const int N=1e6+10;
int a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    
    sort(a+1,a+n+1);
    int res=0;
    for(int i=1;i<=n;i++)res+=abs(a[i]-a[(n+1)/2]);
    cout<<res<<endl;
    
    return 0;
}
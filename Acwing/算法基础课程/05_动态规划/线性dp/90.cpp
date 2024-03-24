#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 895.最长上升子序列
 * 只需要一维来存储状态，f[i]表示以i为结尾的最长子序列的长度
*/
const int N=1010;
int a[N],f[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=n;i++)f[i]=1;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            if(a[j]<a[i])
                f[i]=max(f[i],f[j]+1);
    
    int res=0;
    for(int i=1;i<=n;i++)res=max(res,f[i]);
    cout<<res<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 2 0-1背包问题
 * 将二维压缩成一维，使用滚动数组来进行状态压缩
*/
const int N=1010;
int v[N],w[N];
int f[N];
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];

    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)
            f[j]=max(f[j],f[j-v[i]]+w[i]);
    
    cout<<f[m];

    return 0;
}
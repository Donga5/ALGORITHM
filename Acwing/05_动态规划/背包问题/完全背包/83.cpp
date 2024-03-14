#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 3 完全背包
 * 状态压缩，压缩成一维
 * 类比01背包，但是完全背包f[i][j]=max(f[i-1][j],f[i][j-v]+w);可见是从上一层以及当前层f[i][j-v]转移过来，所以必须从前往后遍历
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
        for(int j=v[i];j<=m;j++)
            f[j]=max(f[j],f[j-v[i]]+w[i]);
    cout<<f[m]<<endl;
    return 0;
}
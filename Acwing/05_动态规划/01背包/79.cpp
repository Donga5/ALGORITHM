#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 2 0-1背包问题
 * 解法2：
 * 二维:遍历j的时候逆序
*/
const int N=1010;
int v[N],w[N];
int f[N][N];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];

    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=0;j--)
        {
            if(j>=v[i])f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
            else f[i][j]=f[i-1][j];//放不下
        }
    }
    cout<<f[n][m]<<endl;

    return 0;
}
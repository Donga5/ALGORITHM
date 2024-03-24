#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 3 完全背包问题
 * 二重循环
 * f[i][j]=max(f[i-1][j],f[i-1][j-v]+w,f[i-1][j-2v]+2w,f[i-1][j-3v]+3w.........)
 * f[i][j-v]=max(        f[i-1][j-v],f[i-1][j-v-v]+w,) 在背包容量比原来已经减少v的情况下和f[i][j]在同一层状态
 * f[i][j]=max(f[i-1][j],f[i][j-v]+w);
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
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];//类比01背包的写法
            if(j>=v[i]) f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);
        }
    cout<<f[n][m]<<endl;
   
    return 0;
}
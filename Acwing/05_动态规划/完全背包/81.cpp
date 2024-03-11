#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 3 完全背包问题
 * 三重循环
 * 
 * 当前代码过不了，超时了
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
            for(int k=0;k*v[i]<=j;k++)
            {
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
            }

    cout<<f[n][m]<<endl;
   
    return 0;
}
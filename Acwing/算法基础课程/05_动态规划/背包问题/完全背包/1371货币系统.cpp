#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 1371货币系统
*/
typedef long long LL;
const int N=30,M=1e4+10;
int n,m;
LL f[N][M];
int w[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i];

    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            if(j>=w[i])
            {
                f[i][j]+=f[i][j-w[i]];
            }
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 2 0-1背包问题
 * 朴素版 
*/
const int N=1010;
int v[N],w[N];
int f[N][N];


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d%d",&v[i],&w[i]);

    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            if(j>=v[i])
            {
                f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
            }
        }
    
    cout<<f[n][m]<<endl;
    return 0;
}
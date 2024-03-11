#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 9分组背包问题
*/
const int N=110;
int v[N][N],w[N][N],s[N];
int f[N][N];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=1;j<=s[i];j++)
        {
            cin>>v[i][j]>>w[i][j];
        }
    }

    //分组背包
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            for(int k=1;k<=s[i];k++)
                if(v[i][k]<=j)
                f[i][j]=max(f[i][j],f[i-1][j-v[i][k]]+w[i][k]);
        }


    //下面这种写法是错误，在循环那里。但是还没有弄清楚为什么
    //      //分组背包
    // for(int i=1;i<=n;i++)
    //     for(int j=0;j<=m;j++)
    //     {
    //         f[i][j]=f[i-1][j];
    //         for(int k=1;v[i][k]<=j&&k<=s[i];k++)
    //             f[i][j]=max(f[i][j],f[i-1][j-v[i][k]]+w[i][k]);
    //     }
    
    
    cout<<f[n][m];
    return 0;
}
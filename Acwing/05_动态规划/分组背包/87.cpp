#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 9 分组背包问题
 * 使用一维
*/
const int N=110;
int v[N][N],w[N][N];
int f[N],s[N];

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

    for(int i=1;i<=n;i++)
        for(int j=m;j>0;j--)
            for(int k=1;k<=s[i];k++)
                if(v[i][k]<=j) f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);//v[i][k]放到外层循环中是错误的
    
    cout<<f[m];
    return 0;
}
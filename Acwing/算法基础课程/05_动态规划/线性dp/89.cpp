#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 898 数字三角形
 * 第二种做法: 倒序从下往上，注意边界问题
*/
const int N=510,INF=5e7+10;
int n;
int f[N][N];
int a[N][N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>a[i][j];

    for(int i=1;i<n;i++)
        for(int j=1;j<=i;j++)
            f[i][j]=-INF;
    //单独初始化最后一行
    for(int i=0;i<=n;i++)f[n][i]=a[n][i];

    for(int i=n-1;i>=1;i--)
        for(int j=1;j<=i;j++)
            f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
    
    cout<<f[1][1];
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 1226包子凑数
 * 完全背包
 * 本题中用到的10000是一个经验值，详细请查看视频
*/
const int N=110,M=10010;
int f[N][M];
int a[N];
int n;

int gcd(int a,int b)
{
    return b ? (gcd(b,a%b)):a;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int d=a[1];
    for(int i=1;i<=n;i++)d=gcd(d,a[i]);

    if(d!=1)
    {
        //最大公约数不是1则有无穷多
        puts("INF");
        return 0;
    }

    f[0][0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<M;j++)
        {
            f[i][j]=f[i-1][j];
            if(j>=a[i])
            {
                f[i][j]|=f[i][j-a[i]];
            }
        }
    }

    int cnt=0;
    for(int i=0;i<M;i++)
    {
        if(!f[n][i])cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
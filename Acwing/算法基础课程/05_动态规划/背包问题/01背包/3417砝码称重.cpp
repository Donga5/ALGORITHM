#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 3417砝码称重
 * 01背包问题
*/
const int N=110,M=200010,B=M/2;
int n,m;
int w[B];
bool f[N][M];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i],m+=w[i];

    f[0][B]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=-m;j<=m;j++)
        {
            f[i][j+B]=f[i-1][j+B];
            if(j-w[i]>=-m)f[i][j+B]|=f[i-1][j-w[i]+B];
            if(j+w[i]<=m)f[i][j+B]|=f[i-1][j+w[i]+B];
        }
    }

    int cnt=0;
    for(int i=1;i<=m;i++)//这里只统计正数部分就行，因为正数和负数部分是对称的
    {
        if(f[n][i+B])cnt++;
    }
    cout<<cnt<<endl;

    //统计了负数部分和0的情况，输出样例得到值应该是21
    // for(int i=1;i<=m;i++)//这里只统计正数部分就行，因为正数和负数部分是对称的
    // {
    //     if(f[n][i+B])cnt++;
    // }

    return 0;
}
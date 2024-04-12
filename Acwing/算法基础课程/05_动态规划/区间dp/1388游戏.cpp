#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 1388游戏
 * 博弈论，区间dp
 * 
 * 基本思路:利用了博弈论，可以看一下题解
 * 其中区间dp的写法是比较固定的
 * 每次计算的是A-B的差，
 * 先手两种情况:
 * 1.选择左边:w[i]-f[i+1][j],当前的w[i]减去对方得到的(B-A最大值)
 * 2.选择右边:w[j]-f[i][j-1],当前的w[j]减去对方(B-A)
 * 
 * 也就是考虑最坏情况下的最大值(因为两方都是选择最优的)
 * 
*/
const int N=110;
int sum=0;
int f[N][N];
int w[N];
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>w[i],sum+=w[i];

    for(int len=1;len<=n;len++)
        for(int i=0;i+len-1<n;i++)
        {
            int j=i+len-1;
            f[i][j]=w[i]-f[i+1][j];
            if(j)
            {
                f[i][j]=max(f[i][j],w[j]-f[i][j-1]);
            }
        }
    cout<<(f[0][n-1]+sum)/2<<" "<<(sum-f[0][n-1])/2<<endl;

    return 0;
}
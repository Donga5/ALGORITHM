#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 282 石子合并
*/
const int N=310;
int s[N];
int f[N][N];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];

    for(int i=1;i<=n;i++)s[i]+=s[i-1];//前缀和

    for(int len=2;len<=n;len++)//枚举区间长度
        for(int i=1;i+len-1<=n;i++)//枚举起点
        {
            int l=i,r=i+len-1;
            f[l][r]=1e8;
            for(int k=l;k<=r-1;k++)//枚举每一个划分点的情况，求出当前区间的最小值
            {
                f[l][r]=min(f[l][k]+f[k+1][r]+s[r]-s[l-1],f[l][r]);
            }
        }
    
    cout<<f[1][n]<<endl;


    return 0;
}
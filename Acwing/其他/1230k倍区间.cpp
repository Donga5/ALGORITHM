#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 1230 k倍区间
 * 前缀和+哈希
*/
typedef long long LL;
const int N=1e6+10;
LL s[N],cnt[N];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&s[i]);
        s[i]+=s[i-1];
    }
    //写法一：
    // LL res=0;
    // for(int i=1;i<=n;i++)
    // {
    //     int t=s[i]%k;
    //     if(t==0)
    //     {
    //         res++;
    //     }
    //     res+=cnt[t];
    //     cnt[t]++;
    // }

    //写法二 y总
    //如果没有cnt[0]=1，那么碰到的第一个s[i]%k==0,就不会被计算，反正最后和正确答案相差的个数是1~n中s[i]%k==0的个数
    LL res=0;
    cnt[0]++;
    for(int i=1;i<=n;i++)
    {
        res+=cnt[s[i]%k];
        cnt[s[i]%k]++;
    }
    cout<<res<<endl;
    return 0;
}

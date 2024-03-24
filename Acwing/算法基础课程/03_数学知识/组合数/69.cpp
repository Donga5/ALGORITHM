#include<iostream>
#include<algorithm>

using namespace std;

/**
 * 886 组合数II
*/
const int N=1e5+10,mod=1e9+7;
int fact[N],infact[N];
typedef long long LL;

int qmi(int a,int k, int q)
{
    int res=1;
    while(k)
    {
        if(k&1)res=(LL)res*a%q;
        k=k>>1;
        a=(LL)a*a%q;
    }
    return res;
}
int main()
{
    //预处理
    fact[0]=infact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=(LL)fact[i-1]*i%mod;
        infact[i]=(LL)infact[i-1]*qmi(i,mod-2,mod)%mod;
    }

    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%lld\n",(LL)fact[a]*infact[b]%mod*infact[a-b]%mod);
    }
    return 0;
}
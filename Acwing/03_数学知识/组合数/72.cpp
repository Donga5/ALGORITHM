#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 889 满足条件的01序列
 * 利用到了公式卡特兰数字,还有更多类型题目查看题解
*/
const int N=1e6+10,mod=1e9+7;
typedef long long LL;

int qmi(int a, int k,int q)
{
    int res=1;
    while(k)
    {
        if(k&1)res=(LL)res*a%q;
        k>>=1;
        a=(LL)a*a%q;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;

    int res=1;
    int a=2*n,b=n;
    for(int i=a;i>=a-b+1;i--)res=(LL)res*i%mod;
    for(int i=n+1;i>=1;i--)res=(LL)res*qmi(i,mod-2,mod)%mod;

    cout<<res<<endl;

    
    return 0;
}
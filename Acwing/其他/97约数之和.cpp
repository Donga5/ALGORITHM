#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 97约数之和
 * 要注意一个数的约数之和 以及 约数的个数如何进行计算 
 * 快速幂，递归，约数
*/
const int mod=9901;

int qmi(int a,int k)
{
    a%=mod;
    int res=1;
    while(k)
    {
        if(k&1)res=a*res%mod;
        k=k>>1;
        a=a*a%mod;
    }
    return res;
}

int sum(int p,int k)
{
    if(k==0)return 1;
    if(k%2==0)return (p%mod*sum(p,k-1)+1)%mod;
    return (sum(p,k/2) * (1+qmi(p,k/2+1)))%mod;
}

int main()
{
    int a,b;
    cin>>a>>b;
    int res=1;
    for(int i=2;i*i<=a;i++)
        if(a%i==0)
        {
            int s=0;
            while(a%i==0)
            {
                a/=i;
                s++;
            }
            res=res*sum(i,s*b)%mod;
        }
    if(a>1)res=res*sum(a,b)%mod;
    if(a==0)res=0;
    cout<<res<<endl;
    return 0;
}
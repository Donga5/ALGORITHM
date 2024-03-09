#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 874 筛法求欧拉函数
 * 本题要注意可能会导致数值溢出，所以要用long long 
*/
const int N=1e6+10;
typedef long long LL;
int n;
int primes[N],cnt;
int pri[N];
bool st[N];

LL get_eulers(int n)
{
    pri[1]=1;
    for(int i=2;i<=n;i++)
    {    
        if(!st[i])
        {
            primes[cnt++]=i;
            pri[i]=i-1;//求出质数的euler
        }
        for(int j=0;primes[j]<=n/i;j++)
        {
            //求出和数euler
            st[primes[j]*i]=true;
            if(i%primes[j]==0)
            {
                pri[primes[j]*i]=pri[i]*primes[j];
                break;
            }
            pri[primes[j]*i]=pri[i]*(primes[j]-1);
        }
    }
    LL res=0;
    for(int i=1;i<=n;i++)
        res+=pri[i];
    return res;   
}

int main()
{
    cin>>n;
    
    cout<<get_eulers(n)<<endl;
    return 0;
}
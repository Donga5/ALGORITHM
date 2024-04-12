#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e6+10;
int prime[N],cnt=0;
bool st[N];

/**
 * 197阶乘分解
*/
void get_primes(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])prime[cnt++]=i;//st[i]主要是为了记录合数
    
        for(int j=0;prime[j]*i<=n;j++)
        {
            st[prime[j]*i]=true;
            if(i%prime[j]==0)break;//i可能不一定是质数
        }
    }
}
int main()
{
    int n;
    cin>>n;
    get_primes(n);
    // cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
    {
        int t=prime[i];
        int s=0;
        int k=n;
        while(k)
        {
            s+=k/t;
            k/=t;   
        }
        printf("%d %d\n",t,s);
    }
    return 0;
}
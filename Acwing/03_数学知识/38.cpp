#include<iostream>
using namespace std;

/**
 * 868 筛质数
 * 线性筛法
 * 
*/
const int N=1e6+10;
int prime[N],cnt;
bool st[N];
void get_primes(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            prime[cnt++]=i;
        }
        for(int j=0;prime[j]<=n/i;j++)
        {
            st[prime[j]*i]=true;
            if(i%prime[j]==0)break;  
        }
    }
    
}

int main()
{
    int n;
    cin>>n;
    get_primes(n);
    cout<<cnt<<endl;
    return 0;
}
#include<iostream>
using namespace std;

/**
 * 868 筛质数
 * 线性筛法：只会被最小质因子筛掉
 * if(i%prime[j]==0)break; 的解释：
 * 这种情况下，prime[j]肯定是i的最小质因子（因为从小到大枚举），如果没有break，那么
 * prime[j]下次增大，再筛掉的下一个数，就不是用最小质因子筛掉了。
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
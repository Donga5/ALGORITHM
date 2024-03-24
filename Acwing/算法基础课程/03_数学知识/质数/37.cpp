#include<iostream>
using namespace std;

/**
 * 868 筛质数
 * 朴素筛法
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
            //如果到i的时候，还没有被筛过，说明是质数
            prime[cnt++]=i;
            for(int j=i+i;j<=n;j+=i)st[j]=true;//使用质数筛即可
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
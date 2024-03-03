#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * 871约数之和
 * 两个整数的最大公约数是能够同时整除它们的最大的正整数。辗转相除法基于如下原理：两个整数的最大公约数等于其中较小的数和两数的相除余数的最大公约数。
 * 例如，252和105的最大公约数是21（252 = 21 × 12；105 = 21 × 5）；因为252 / 105 = 2余42，所以105和42的最大公约数也是21。在这个过程中，较大的数缩小了，所以继续进行同样的计算可以不断缩小这两个数直至其中一个变成零。
 * 这时，所剩下的还没有变成零的数就是两数的最大公约数。由辗转相除法也可以推出，两数的最大公约数可以用两数的整数倍相加来表示，
*/
const int N=110,mod=1e9+7;
typedef long long LL;
int main()
{
    int n;
    cin>>n;
    unordered_map<int,int>primes;
    while(n--)
    {
        int x;
        cin>>x;
        for(int i=2;i<=x/i;i++)
            while(x%i==0)
            {
                x/=i;
                primes[i]++;
            }
        if(x>1)primes[x]++;
    }

    LL res=1;
    for(auto prime:primes)
    {
        int p=prime.first,a=prime.second;
        LL sum=1;
        while(a--)
        {
            sum=(sum*p+1)%mod;
        }
    
        res=(res*sum)%mod;    
    }

    cout<<res<<endl;

    return 0;
}
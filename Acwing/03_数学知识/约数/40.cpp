#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
/**
 * 870约数个数
 * 对读入的每个数进行质因数分解，然后将他们的指数相加，相当于对他们的乘积进行质因数分解
*/
const int N=110, mod=1e9+7;
typedef long long LL;

unordered_map<int,int> primes;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        scanf("%d",&x);
        for(int i=2;i<=x/i;i++)
            while(x%i==0)
            {
                x/=i;
                primes[i]++;//增加对应数字次幂
            }
        if(x>1)primes[x]++;
    }

    LL res=1;//存储乘积，为了防止溢出
    for(auto prime:primes)
    {
        res=res*(prime.second+1)%mod;//为了防止溢出,每次都要进行取余
    }
    cout<<res<<endl;

    return 0;
}
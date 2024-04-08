#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 3491完全平方数
 * 一定别忘记这里n的范围，还有是i的范围
 * 质因数分解 
*/
typedef long long LL;
LL n;

int main()
{
    cin>>n;
    
    LL res=1;
    for(LL i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int s=0;
            while(n%i==0)
            {
                s++;
                n/=i;
            }
            if(s%2)
            {
                res*=i;
            }
        }
    }
    if(n>1)res*=n;
    cout<<res<<endl;
    return 0;
}
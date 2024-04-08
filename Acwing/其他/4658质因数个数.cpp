#include<iostream>
using namespace std;

/**
 * 4658质因数个数
 * 质因数分解
 * 要注意数据范围，x和循环里边的值都应该是long long 
 * 因为i*i可能会爆掉int
*/
typedef long long ll;


int main()
{
    ll x;
    cin>>x;
    ll res=0;
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0) 
        {
            while(x%i==0)x/=i;
            res++;
        }
    }
    if(x>1)res++;
    cout<<res<<endl;
    return 0;
}
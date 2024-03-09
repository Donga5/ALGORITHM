#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 876 快速幂求逆元
*/
typedef long long LL;

int qmi(int a,int k,int p)
{
    int res=1;
    while(k)
    {
        if(k&1)res=(LL)res*a%p;
        k=k>>1;
        a=(LL)a*a%p;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,p;
        scanf("%d%d",&a,&p);
        if(a%p==0)puts("impossible");
        else cout<<qmi(a,p-2,p)<<endl;
    }

    return 0;
}
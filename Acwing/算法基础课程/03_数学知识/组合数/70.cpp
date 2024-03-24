#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/**
 * 887 组合数III
*/
typedef long long LL;

int qmi(int a, int k,int p)
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

//循环：直接按照组合数最基本公式计算
int C(int a,int b,int p)
{
    if(b>a)return 0;
    int res=1;
    for(int i=1,j=a;i<=b;i++,j--)
    {
        res=(LL)res*j%p;
        res=(LL)res*qmi(i,p-2,p)%p;
    }
    return res;
}


LL lucas(LL a,LL b,int p)
{
    if(a<p&&b<p)return C(a,b,p);
    return (LL)C(a%p,b%p,p)*lucas(a/p,b/p,p)%p;
}


int main()
{
    int n;
    scanf("%d",&n);
    LL a,b;
    int p;
    while(n--)
    {
        cin>>a>>b>>p;
        cout<<lucas(a,b,p)<<endl;
    }

    return 0;
}
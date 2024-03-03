#include<iostream>
using namespace std;

/**
 * 872. 最大公约数 
 * 主要就是利用 gcd(a,b)==gcd(b,a%b)相等得来
 * 
 * gcd函数解释,
 * 当b为0的时候，a>0 a和b的最大公约数为a
*/
int gcd(int a,int b)
{
    return b? gcd(b,a%b):a;
}

int main()
{
    int n;
    cin>>n;
    int a,b;
    while(n--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",gcd(a,b));
    }

    return 0;
}
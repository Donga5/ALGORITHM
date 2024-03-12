#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
/**
 * 875 快速幂
 * 注意数据范围,本题中间结果可能会出现超过int的情况,但是最终的%p结果不会超过int
*/
int qmi(int a,int k,int p)
{
    int res=1;
    while(k)
    {
        if(k&1)res=(LL)res*a%p;
        k=k>>1;//方便下次循环获得二进制最后一位
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
        int a,k,p;
        scanf("%d%d%d",&a,&k,&p);
        printf("%d\n",qmi(a,k,p));
    }

    return 0;
}
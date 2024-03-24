#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * 888求组合数IV
 * 1.求出1-a所有质因数
 * 2.求出最后的组合数中包含的质因子的次数
 * 3.利用高精度乘法进行计算
 
 */
const int N = 5010;
typedef long long LL;
int primes[N], cnt;
bool st[N];
int sum[N];

//预处理1-N的所有质数
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j]==0)
                break;
        }
    }
}
//获取n的阶乘中p的个数
int get(int n,int p)
{
    int res=0;
    while(n)
    {
        res+=n/p;
        n/=p;
    }
    return res;
}

vector<int> mul(vector<int>&a,int b)
{
    vector<int>res;
    int t=0;
    for(int i=0;i<a.size();i++)
    {
        t+=a[i]*b;
        res.push_back(t%10);
        t/=10;
    }
    //处理最高位
    while(t)
    {
        res.push_back(t%10);
        t/=10;
    }
    return res;
}


int main()
{


    int a, b;
    cin>>a>>b;
    get_primes(a);

    //分解质因数，得到最后的组合数结果中，各个质因子的次数
    for(int i=0;i<cnt;i++)
    {
        int p=primes[i];
        sum[i]=get(a,p)-get(b,p)-get(a-b,p);
    }

    vector<int> res;
    res.push_back(1);
    //依次使用高精度乘法想乘
    for(int i=0;i<cnt;i++)
        for(int j=0;j<sum[i];j++)
            res=mul(res,primes[i]);

    //输出结果
    for(int i=res.size()-1;i>=0;i--)
        printf("%d",res[i]);
    puts("");


    return 0;
}
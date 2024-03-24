#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

/**
 * 338 计数问题
 * 暴力枚举
 * 类似前缀和的思想,但是这道题目数据室太大，肯定是会TLE
*/

int force_count(int a,int x)
{
    int res=0;
    if(x==0)res++;
    for(int i=1;i<=a;i++)
    {
        int t=i;
        while(t)
        {
            if(t%10==x)res++;
            t/=10; 
        }
    }
    return res;
}


int main()
{
    int a,b;
    while(cin>>a>>b,a||b)
    {
        if(a>b)swap(a,b);
        for(int i=0;i<=9;i++)
        {
            cout<<(force_count(b,i)-force_count(a-1,i))<<" ";
        }
        puts("");
    }
    return 0;
}
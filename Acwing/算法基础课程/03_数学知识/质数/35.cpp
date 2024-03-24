#include<iostream>
using namespace std;
/**
 * 866. 试除法判定质数
 * 截止条件三种写法：
 * 1.i*i<x 可能会溢出，溢出之后变成负数
 * 2.i<sqrt(x) 这个比较慢
 * 3.i<x/i (最好是这样写)
*/
bool is_prime(int x)
{
    if(x<2)return false;
    for(int i=2;i<=x/i;i++)
        if(x%i==0)
            return false;
    return true;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        if(is_prime(x))puts("Yes");
        else puts("No");
    }
    return 0;
}
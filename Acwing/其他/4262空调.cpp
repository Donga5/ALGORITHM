#include<iostream>
#include<algorithm>
using namespace std;
/**
 * 4262空调
*/
const int N=1e5+10;
int a[N];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int b;
        cin>>b;
        //计算差值
        a[i]-=b;
    }

    
    //两种写法：本质上相同，可以结合两种方法看一下
    //构造差分数组
    // for(int i=n+1;i;i--)a[i]-=a[i-1];//倒着求，不然会被覆盖,同时假设原数组中最后一位为0
    // int res=0;
    // for(int i=1;i<=n+1;i++)
    //     if(a[i]>0)res+=a[i];//正数和负数个数相同,只统计一个即可
    // cout<<res<<endl;

    //第二种写法,还是假设原数组中最后一位为0，那么差分数组中pos和neg的绝对值的差值直接在最后一位补上就行
    for(int i=n;i;i--)a[i]-=a[i-1];
    int pos=0,neg=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)pos+=a[i];
        else neg-=a[i];
    }
    cout<<max(pos,neg)<<endl;

    return 0;
}
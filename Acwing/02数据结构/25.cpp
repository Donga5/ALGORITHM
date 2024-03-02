#include<iostream>
using namespace std;

/**
 * 单调队列
*/
const int N=1e6+10;
int a[N],q[N];//q[N]记录的是下标值
int hh=0,tt=-1;

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);

    for(int i=0;i<n;i++)//i是窗口的最右端
    {
        if(hh<=tt&& i-k+1 > q[hh])hh++;//保证hh没有滑出窗口
        while(hh<=tt&&a[q[tt]]>=a[i])tt--;//如果新加入的a[i]不能使得队列中成为一个生成序列，则将前面的数据弹出
        q[++tt]=i;//必须先进行赋值，因为a[i]可能足够小，会把队列清空掉，不赋值先输出会有问题
        if(i>=k-1)printf("%d ",a[q[hh]]);
    }
    puts("");

    //求滑动窗口的最大值
    hh=0,tt=-1;
    for(int i=0;i<n;i++)//i是窗口的最右端
    {
        if(hh<=tt&& i-k+1 > q[hh])hh++;//保证队列头没有滑出窗口
        while(hh<=tt&&a[q[tt]]<=a[i])tt--;//如果新加入的a[i]不能使得队列中成为一个生成序列，则将前面的数据弹出
        q[++tt]=i;
        if(i>=k-1)printf("%d ",a[q[hh]]);
    }

    return 0;
}
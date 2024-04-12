#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/**
 * 135 最大子序和
 * 前缀和
*/
typedef long long LL;
const int N=3e5+10;
int a[N];
LL s[N];
int q[N];
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];

    LL res=-(1<<31);
    // cout<<res<<endl;

    int hh=0,tt=0; //实际上已经把s[0]也就是q[0]=0放进去了
    //所以此时队列实际上是不空的
    //如果这里的tt初始化为-1,那么第一个放入的就是s[1]了
    for(int i=1;i<=n;i++)
    {
        if(i-m>q[hh])hh++;
        res=max(res,s[i]-s[q[hh]]);
        while(hh<=tt&&s[q[tt]]>=s[i])tt--;
        q[++tt]=i;
    }
    cout<<res<<endl;
    return 0;
}
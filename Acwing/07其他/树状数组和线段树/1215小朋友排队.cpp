#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/**
 * 1215小朋友排队
 * 树状数组
 * 每个小朋友交换的次数恰好是它前面比它大的数的个数以及后边比它小的数的个数之和。
 * 可以对比冒泡排序进行思考
 * 注意这里的树状数组的含义和数组的下标范围。
*/
const int N=1e5+10,M=1e6+10;
typedef long long LL;
int h[N];
int tr[M];//树状数组中存的是在一定区间内下标对应的个数前缀和，所以下标范围是数的范围
int sum[N];
int n;

int lowbit(int x)
{
    return x&-x;
}
void add(int x,int v)
{
    for(int i=x;i<M;i+=lowbit(i))tr[i]+=v;
}
int query(int x)
{
    int s=0;//tr里边存的数的范围不会超过1e5
    for(int i=x;i;i-=lowbit(i))s+=tr[i];
    return s;
}

int main()
{
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
        h[i]+=1;
        //求前面比该数字大的数
        sum[i]+=query(M-1)-query(h[i]);
        add(h[i],1);
    }
    memset(tr,0,sizeof(tr));
    for(int i=n;i>=1;i--)//倒序添加
    {
        //求后面比它小的数字
        sum[i]+=query(h[i]-1);
        add(h[i],1);
    }
    LL s=0;
    for(int i=1;i<=n;i++)s+=(LL)sum[i]*(sum[i]+1)/2;
    cout<<s<<endl;



    return 0;
}
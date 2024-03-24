#include<iostream>
#include<algorithm>
using namespace std;
/**
 * 3745牛的学术圈
 * 1.排序
 * 2.枚举h,i指向大于等于h的第一个值，如果区间长度符合要求，则该h满足。
 *   否则j=i，向左寻找等于h-1的值，有多少个，最能只能是m个。加上这些看区间长度是否符合要求.
*/
const int N=1e5+10;
int n,m;
int a[N];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);

    int i=0,h;
    for(h=0;h<N;h++)
    {
        while(a[i]<h&&i<n)i++;
        if(a[i]>=h&&n-i>=h)continue;
        int j=i,cnt=0;
        while(j>=1&&a[j-1]==h-1)j--,cnt++;
        cnt=min(cnt,m);//最多可以往左移动的次数
        if(cnt+n-i<h)break;
    }
    cout<<max(0,h-1)<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 3745牛的学术圈
 * 双指针+二分,这个时间复杂度为o(nlogn)
*/
const int N=1e5+10;
int a[N];
int n,m;

bool check(int h)
{
    int i=0;
    while(a[i]<h&&i<n)i++;
    if(a[i]>=h&&n-i>=h)return true;
    int j=i,cnt=0;
    while(j>=1&&a[j-1]==h-1)cnt++,j--;
    cnt=min(cnt,m);
    if(cnt+n-i>=h)return true;
    return false;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int l=0,r=1e5;
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<r<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 125 耍杂技的牛
*/
typedef pair<int,int>PIT;
const int N=5e4+10;
typedef long long LL;


bool cmp(const PIT&a,PIT &b)
{
    return (a.first+a.second)<(b.first+b.second);
}

PIT a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int w,s;
        scanf("%d%d",&w,&s);
        a[i]={w,s};
    }
    sort(a,a+n,cmp);
    LL sum=0,res=-2e9;
    for(int i=0;i<n;i++)
    {
        res=max(res,sum-a[i].second);
        sum+=a[i].first;
    }
    cout<<res<<endl;
    return 0;
}
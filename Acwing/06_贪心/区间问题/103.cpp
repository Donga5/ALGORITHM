#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std ;

/**
 * 905 区间选点
 * 贪心算法，首先进行排序，然后再找
*/
const int N=1e5+10;
struct Range
{   
    int l,r;
    bool operator < (const Range&w)const 
    {
        return r<w.r;
    }
}ranges[N];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ranges[i]={a,b};
    }
    sort(ranges,ranges+n);

    int res=0,eg=-2e9;
    for(int i=0;i<n;i++)
    {
        if(ranges[i].l>eg)
        {
            res++;
            eg=ranges[i].r;
        }
    }

    cout<<res<<endl;

    return 0;
}
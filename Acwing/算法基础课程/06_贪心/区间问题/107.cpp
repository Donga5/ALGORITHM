#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;

/**
 * 907区间覆盖
 * 这道题要注意边界问题 
*/
struct Range
{
    int l,r;
    bool operator < (const Range&w)const{
        return l<w.l;
    }
}ranges[N];

int main()
{
    int start,end;
    cin>>start>>end;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ranges[i]={a,b};
    }
    sort(ranges,ranges+n);
    
    //双指针+贪心
    int res=0;bool is_success=false;
    for(int i=0;i<n;i++)
    {
        int j=i,t=-2e9;
        for(;j<n&&start>=ranges[j].l;j++)
        {
            t=max(t,ranges[j].r);
        }
        if(t<start)
        {
            res=-1;
            break;
        }
        res++;
        if(t>=end)
        {
            is_success=true;
            break;
        }
        i=j-1;
        start=t;
    }
    if(!is_success)res=-1;
    cout<<res<<endl;
    return 0;
}
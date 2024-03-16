#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/**
 * 908 最大不相交区间
 * 使用vector+pair的方式,练习一下对于pair的自定义排序方式
*/


bool sort_by_second(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.second < b.second;
}
int main()
{
    vector<pair<int,int>>ranges;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ranges.push_back({a,b});
    }
    sort(ranges.begin(),ranges.end(),sort_by_second);

    int res=0,eg=-2e9;
    for(auto range:ranges)
    {
        if(range.first>eg)
        {
            res++;
            eg=range.second;
        }

    }
    cout<<res<<endl;
    return 0;
}

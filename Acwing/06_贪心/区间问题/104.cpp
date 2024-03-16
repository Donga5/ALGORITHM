#include<iostream>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;

#define x first //右端点
#define y second//左端点

/**
 * 908最大不相交区间
 * 使用了pair
*/
const int N=1e5+10;
typedef pair<int,int>PIT;
PIT ranges[N];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ranges[i]={b,a};
    }

    sort(ranges,ranges+n);//按照右端点排序
    int res=0,eg=-2e9;
    for(int i=0;i<n;i++)
    {
        if(ranges[i].y>eg)
        {
            res++;
            eg=ranges[i].x;
        }
    }

    cout<<res<<endl;
    return 0;
}
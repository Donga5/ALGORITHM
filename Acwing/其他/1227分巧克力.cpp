#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/**
 * 1227分巧克力
*/

const int N=1e5+10;
int n,m;
typedef pair<int,int>PIT;
PIT a[N];
int mmax;

#define x first
#define y second

bool check(int mid)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(mid>a[i].x||mid>a[i].y)continue;
        cnt+=((a[i].x/mid) * (a[i].y / mid));
    }
    if(cnt>=m)return true;
    else return false;
}


int main()
{
    cin>>n>>m;
    
    for(int i=0;i<n;i++)
    {
        int h,w;
        scanf("%d%d",&h,&w);
        mmax=max(mmax,h);
        a[i]={h,w};
    }    

    int l=1,r=mmax;
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }

    cout<<l<<endl;
    return 0;
}
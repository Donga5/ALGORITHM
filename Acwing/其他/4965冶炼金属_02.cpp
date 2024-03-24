#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e4+10;
typedef pair<int,int> PIT;
PIT a[N];

int n;
bool check_l(int x)
{
    for(int i=0;i<n;i++)
        if(a[i].first/(a[i].second+1)+1 >x)return false;
    return true;
}

bool check_r(int x)
{
    for(int i=0;i<n;i++)
        if(a[i].first/a[i].second < x)return false;
    return true;
}

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }

    int l=0,r=1e9+10;
    while(l<r)
    {
        int mid=l+r>>1;
        if(check_l(mid))r=mid;
        else l=mid+1;
    }

    cout<<l<<" ";

    
    l=0,r=1e9+10;
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(check_r(mid))l=mid;
        else r=mid-1;
    }
    cout<<l<<" "<<endl;
    return 0;
}
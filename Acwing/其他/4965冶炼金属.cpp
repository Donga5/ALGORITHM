#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int l=0,r=2e9;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        l=max(l,a/(b+1)+1),r=min(r,(a/b));
    }
    cout<<l<<" "<<r;
    return 0;
}
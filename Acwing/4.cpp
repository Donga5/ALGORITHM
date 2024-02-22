#include<iostream>
//利用浮点数二分求平方根
using namespace std;

int main()
{
    double x;
    cin>>x;

    double l=0,r=x;
    while(r-l>=1e-8)
    {
        double mid=(l+r)/2;
        if(mid*mid>=x)r=mid;
        else l=mid;
    }
    cout<<l;
    return 0;
}
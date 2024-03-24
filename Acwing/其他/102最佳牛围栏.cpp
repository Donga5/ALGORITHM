#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 102最佳牛围栏
 * 
 * 考点：二分，前缀和，平均数，
 * 基本思路
 * 1.注意数值类型要使用double,使用浮点数二分模板
 * 2.注意平均数的使用技巧。减去avg之后就可以转化s[j]>=s[i]作为条件,总体算法的时间复杂度为o(nlogn)
 * 
 * 如果没有共同减去一个平均数，那么每次判定的时候就需要扫描整个区间，这样的话，会增加时间复杂度
*/
const int N=1e6+10;
int a[N];
int n,m;
double s[N];

bool check(double avg)
{
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i]-avg;
    double minv=0;
    for(int i=0,j=m;j<=n;i++,j++)
    {
        minv=min(minv,s[i]);
        if(s[j]>=minv)return true;
    }
    return false;
}


int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    double l=1,r=2000;
    while(r-l>1e-5)
    {
        double mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<(int)(r*1000)<<endl;

    return 0;
}
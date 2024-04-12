#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 1246等差数列
 * 最大公约数
*/
const int N=1e5+10;
int a[N];
int n;

int gcd(int a,int b)
{
    return b ? gcd(b,a%b):a;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    int st=a[0],ed=a[n-1];
    for(int i=0;i<n-1;i++)a[i]=a[i+1]-a[i];
    
    int d=a[0];
    for(int i=0;i<=n-2;i++)
        d=min(d,gcd(d,a[i]));
    
    if(!d)cout<<n<<endl;
    else
    cout<<(ed-st)/d+1<<endl;
    return 0;
}
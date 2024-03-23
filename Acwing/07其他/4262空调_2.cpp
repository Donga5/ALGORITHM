#include<iostream>
#include<algorithm>
using namespace std;
/**
 * 4262空调
*/
const int N=1e5+10;
int a[N],b[N];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int c;
        cin>>c;
        //计算差值
        a[i]-=c;
    }

    //不在原数组的基础上构造差分
    for(int i=1;i<=n;i++)b[i-1]-=a[i],b[i]+=a[i];
    
    int pos=0,neg=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>0)pos+=b[i];k
        else neg-=b[i];
    }
    cout<<max(pos,neg)<<endl;

    return 0;
}
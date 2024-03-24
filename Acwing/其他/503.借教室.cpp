#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/**
 * 503借教室
 * 两种方法均可
*/
typedef long long LL;
const int N=1e6+10;
int a[N];
LL b[N];
int d[N],s[N],t[N];
int n,m;

bool check(int mid)
{
    for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
    for(int i=1;i<=mid;i++)
    {
        b[s[i]]-=d[i];
        b[t[i]+1]+=d[i];
    }
    for(int i=1;i<=n;i++)
    {
        b[i]+=b[i-1];
        if(b[i]<0)return true;
    }
    return false;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&d[i],&s[i],&t[i]);
    }

    int l=1,r=m;
    while(l<r)
    {
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;     
    }

    if(!check(m))cout<<0<<endl;
    else cout<<-1<<endl<<r<<endl;

    return 0;
}


// #include<iostream>
// #include<algorithm>
// #include<cstring>
// using namespace std;

/**
 * 503借教室
*/
// typedef long long LL;
// const int N=1e6+10;
// int a[N];
// LL b[N];
// int d[N],s[N],t[N];
// int n,m;

// bool check(int mid)
// {
//     for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
//     for(int i=1;i<=mid;i++)
//     {
//         b[s[i]]-=d[i];
//         b[t[i]+1]+=d[i];
//     }
//     for(int i=1;i<=n;i++)
//     {
//         b[i]+=b[i-1];
//         if(b[i]<0)return false;
//     }
//     return true;
// }

// int main()
// {
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)scanf("%d",&a[i]);
//     for(int i=1;i<=m;i++)
//     {
//         scanf("%d%d%d",&d[i],&s[i],&t[i]);
//     }

//     int l=1,r=m;
//     while(l<r)
//     {
//         int mid=l+r>>1;
//         if(check(mid))l=mid+1;
//         else r=mid;     
//     }

//     if(check(m))cout<<0<<endl;
//     else cout<<-1<<endl<<r<<endl;

//     return 0;
// }
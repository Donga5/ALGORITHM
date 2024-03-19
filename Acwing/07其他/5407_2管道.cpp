#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 5407管道
 * 二分+区间合并模板
*/
#define x first
#define y second 
const int N=1e5+10;
typedef long long LL;
typedef pair<int,int>PIT;
PIT w[N],q[N];
int n,len;

bool check(int mid)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(w[i].y>mid)continue;
        int t=mid-w[i].y;
        int l=max((LL)1,(LL)w[i].x-t),r=min((LL)len,(LL)w[i].x+t);
        q[cnt++]={l,r};    
    }

    sort(q,q+cnt);

    //这种做法好，不用再处理边界情况
    int st=-1,ed=-1;
    for(int i=0;i<cnt;i++)
    {
        if(ed+1>=q[i].x)ed=max(ed,q[i].y);
        else st=q[i].x,ed=q[i].y;        
    }

    return st==1&&ed==len;

}

int main()
{
    cin>>n>>len;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&w[i].x,&w[i].y);
    }

    int l=1,r=2e9;
    while(l<r)
    {
        int mid=(LL)l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}
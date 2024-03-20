#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/**
 * 多路归并,贪心，多路归并
*/
const int N=110;
int a[N],s[N],l[N];
int spend[N];//每个上面的话费的时间
int n;

int get(int i)
{
    return max(0,a[i]-s[i]*spend[i]);
}


int work(int m,int T)
{
    int res=0;
    memset(spend,0,sizeof(spend));

    for(int i=1;i<=T;i++)
    {
        int t=1;
        for(int j=2;j<=m;j++)
            if(get(t)<get(j))
                t=j;
        res+=get(t);
        spend[t]++;
    }
    return res;
}

int main()
{
    int T;
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&s[i]);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&l[i]);
        l[i]+=l[i-1];//前缀和表示
    }

    scanf("%d",&T);

    int res=0;
    for(int i=1;i<=n;i++)
    {
        res=max(res,work(i,T-l[i]));
    }
    cout<<res<<endl;
    return 0;
}
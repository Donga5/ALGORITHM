#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/**
 * 562壁画
*/
const int N=5e6+10;
int a[N],s[N];
char str[N];
int n,T;

int main()
{
    cin>>T;
    for(int k=1;k<=T;k++)
    {
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        cin>>n;
        scanf("%s",str+1);
        for(int i=1;i<=n;i++)
        {
            a[i]=str[i]-'0';
            s[i]=s[i-1]+a[i];
        }
        int t=n/2;
        if(n%2==1)t+=1;
        int res=0;
        for(int i=1,j=0;j<=n;i++)
        {
            j=i+t-1;
            res=max(res,s[j]-s[i-1]);
        }
        printf("Case #%d: %d\n",k,res);
    }

    return 0;
}
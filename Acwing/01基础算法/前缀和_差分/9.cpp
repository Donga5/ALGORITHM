#include<iostream>

using namespace std;
const int N=1e6+10;
int n,m;

int a[N],s[N];//原数组和前缀和数组

int main()
{
    scanf("%d%d",&n,&m);
    //注意0的位置不使用
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];

    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",s[r]-s[l-1]);
    }    
    
    return 0;
}
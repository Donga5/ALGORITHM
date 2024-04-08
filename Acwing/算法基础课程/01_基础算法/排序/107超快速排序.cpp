#include<iostream>
#include<algorithm>

/**
 * 107超快速排序，逆序对,归并排序
*/
const int N=5e5+10;
int q[N],w[N];
int n;
typedef long long LL;
LL merge_sort(int l,int r)
{
    if(l==r)return 0;
    int mid=l+r>>1;
    LL res=merge_sort(l,mid)+merge_sort(mid+1,r);
    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j])w[k++]=q[i++];
        else 
        {
            res+=mid-i+1;
            w[k++]=q[j++];
        }
    }
    while(i<=mid)w[k++]=q[i++];
    while(j<=r)w[k++]=q[j++];
    for(int i=l,j=0;i<=r;i++,j++)q[i]=w[j];
    return res;
    
}
int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)scanf("%d",&q[i]);
        printf("%lld\n",merge_sort(0,n-1));
    }
    return 0;
}
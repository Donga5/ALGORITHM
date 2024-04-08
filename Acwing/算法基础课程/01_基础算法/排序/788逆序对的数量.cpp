#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 788逆序对的数量，归并排序
*/
typedef long long LL;
const int N=1e6+10;
int n;
int q[N],tmp[N];

LL merge_sort(int q[],int l,int r)
{
    if(l>=r)return 0;
    int mid=l+r>>1;
    
    LL r1=merge_sort(q,l,mid);
    LL r2=merge_sort(q,mid+1,r);
    LL res=r1+r2;
    //归并
    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j])tmp[k++]=q[i++];
        else 
        {
            tmp[k++]=q[j++];
            res+=mid-i+1;
        }
    }
    while(i<=mid)tmp[k++]=q[i++];
    while(j<=r)tmp[k++]=q[j++];
    for(int i=l,j=0;i<=r;i++)q[i]=tmp[j++];
    return res;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",&q[i]);
    LL res=merge_sort(q,0,n-1);

    cout<<res<<endl;
    for(int i=0;i<n;i++)printf("%d ",q[i]);
    
    return 0;
}
/**
 * quicksort 快速排序代码模板
 * 基准可以是左边，右边，或则中间值，或者是随机
*/
#include<iostream>
using namespace std;

const int N=1e5+10;
int q[N];

void quick_sort(int q[],int l, int r)
{
    if(l>=r) return; //递归边界

    int x=q[l],i=l-1,j=r+1;//以左边作为基准
    while(i<j)
    {
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort(q,l,j);//注意这里的边界并没有使用i
    quick_sort(q,j+1,r);
}


int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    quick_sort(q,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",q[i]);

    return 0;
}



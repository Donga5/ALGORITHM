#include<iostream>
#include<cstdio>
/**
 * 归并排序主要思想：
 * 1. 分治：将数组一分为二，分别对两个数组进行排序
 * 2. 合并：将两个有序数组合并为一个有序数组
*/
using namespace std;
const int N = 1e5+10;
int q[N],tmp[N];//存储数据和临时结果

void merge_sort(int q[],int l, int r)
{
    if(l>=r)return;
    int mid=(l+r)>>1; //确定数组的中间位置
    merge_sort(q,l,mid);//递归排序左右两边
    merge_sort(q,mid+1,r);
    //合并
    int k=0,i=l,j=mid+1;
    while(i<=mid && j<=r)
    {
        //结果通过双指针算法合并到tmp数组中
        if(q[i]<=q[j])tmp[k++]=q[i++];
        else tmp[k++]=q[j++];
    }
    while(i<=mid)tmp[k++]=q[i++];
    while(j<=r)tmp[k++]=q[j++];
    //结果复制到原数组当中 ,注意这里复制的是从l到r的部分，因为有递归
    for(int i=l, j=0; i<=r; i++, j++)q[i]=tmp[j];
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&q[i]);
    merge_sort(q,0,n-1);

    for(int i=0;i<n;i++)printf("%d ",q[i]);

    return 0;
}
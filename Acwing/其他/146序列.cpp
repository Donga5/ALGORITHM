#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
/**
 * 146序列
 * 多路归并
 * 基本思路:
 * 每次将两个序列进行合并，然后保存前n个最小的值。然后两两进行合并，最后得到的序列就是答案。
 * 具体如何合并:
 * 1.将序列a排序。
 * 2.分组，每个a和b中每个值组成一个组。则可以有n个组，转换为多路归并问题。类似钓鱼。
*/
typedef pair<int,int> PIT;
const int N=2010;
int a[N],b[N],c[N];
int n,m;

void merge()
{
    priority_queue<PIT,vector<PIT>,greater<PIT>> heap;
    //堆初始化
    for(int i=0;i<n;i++)heap.push({a[0]+b[i],0});
    for(int i=0;i<n;i++)
    {
        auto t=heap.top();
        heap.pop();
        int x=t.first,p=t.second;
        c[i]=x;//存储到临时数组中
        heap.push({x-a[p]+a[p+1],p+1});
    }
    for(int i=0;i<n;i++)a[i]=c[i];
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&m,&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);//读入第一行
        sort(a,a+n);//将a排序
        
        for(int i=1;i<m;i++)//合并m-1次
        {
            for(int i=0;i<n;i++)scanf("%d",&b[i]);
            merge();
        }

        for(int i=0;i<n;i++)printf("%d ", a[i]);
        puts("");
    }
    return 0;
}
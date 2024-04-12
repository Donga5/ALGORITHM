#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 4964子矩阵
 * 单调队列
 * 基本思想:
 * 预处理来每一行的所有窗口的最大值和最小值
 * 选定列的某一长条，计算该区间内的所有 子矩阵的最大值和最小值，然后相加
 * 这里的取余一定要注意，最外层中要对结果进行取余
*/
typedef long long LL;
const int N=1010,mod=998244353;
int w[N][N];
int n,m;
int A,B;
int rmin[N][N];//预处理每一行窗口内的最大值和最小值
int rmax[N][N];
int q[N];

void get_min(int a[],int b[],int cnt,int k)
{
    int hh=0,tt=-1;
    for(int i=0;i<cnt;i++)
    {
        if(hh<=tt&&i-k+1>q[hh])hh++;
        while(hh<=tt&&a[q[tt]]>=a[i])tt--;
        q[++tt]=i;
        b[i]=a[q[hh]];
    }   
}

void get_max(int a[],int b[],int cnt,int k)
{
    int hh=0,tt=-1;
    for(int i=0;i<cnt;i++)
    {
        if(hh<=tt&&i-k+1>q[hh])hh++;
        while(hh<=tt&&a[q[tt]]<=a[i])tt--;
        q[++tt]=i;
        b[i]=a[q[hh]];
    }   
}


int main()
{
    cin>>n>>m;
    cin>>A>>B;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)scanf("%d",&w[i][j]);
    
    for(int i=0;i<n;i++)
    {
        get_min(w[i],rmin[i],m,B);
        get_max(w[i],rmax[i],m,B);
    }

    int a[N],b[N],c[N];
    LL s=0;
    for(int i=B-1;i<m;i++)//竖条的最后一列的下标
    {
        for(int j=0;j<n;j++)a[j]=rmin[j][i];
        get_min(a,b,n,A);
        for(int j=0;j<n;j++)a[j]=rmax[j][i];
        get_max(a,c,n,A);
        for(int j=A-1;j<n;j++)
            s=(s+(LL)b[j]*c[j])%mod;
    }
    cout<<s<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

/**
 * 1091理想的正方形
 * 二维单调队列优化
 * 注意这里还是q[]的大小还是要保证和行的范围相同
*/
const int N=1010;
int n,m;
int A;
int w[N][N];
int q[N];
int rmin[N][N];//每行窗口的最大值和最小值
int rmax[N][N];

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
    cin>>n>>m>>A;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)scanf("%d",&w[i][j]);

    for(int i=0;i<n;i++)
    {
        get_min(w[i],rmin[i],m,A);
        get_max(w[i],rmax[i],m,A);
    }

    int a[N],b[N],c[N];
    int res=2e9;
    for(int i=A-1;i<m;i++)
    {
        for(int j=0;j<n;j++)a[j]=rmin[j][i];
        get_min(a,b,n,A);
        for(int j=0;j<n;j++)a[j]=rmax[j][i];
        get_max(a,c,n,A);
        for(int j=A-1;j<n;j++)
            res=min(res,c[j]-b[j]);
    }
    cout<<res<<endl;
    return 0;
}
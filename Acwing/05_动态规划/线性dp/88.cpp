#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 898 数字三角形
*/
const int N=510,INF=5e7+10;
int n;
int f[N][N];
int a[N][N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)   
        for(int j=1;j<=i;j++)
            cin>>a[i][j];

    //初始化状态数组
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i+1;j++)
            f[i][j]=-INF;
    
    //初始化边界值
    f[1][1]=a[1][1];
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
            f[i][j]=max(f[i-1][j-1],f[i-1][j])+a[i][j];

    //遍历最后一行
    int res=-INF;
    for(int i=1;i<=n;i++)   
        res=max(res,f[n][i]);

    cout<<res;    
    return 0;
}
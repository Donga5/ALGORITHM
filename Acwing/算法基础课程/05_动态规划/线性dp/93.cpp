#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 897 最长公共子序列
 * f[i,j]其实可以拆分成四种情况，详细查看笔记
*/
const int N=1010;
char a[N],b[N];
int n,m;
int f[N][N];

int main()
{
    cin>>n>>m;
    scanf("%s%s",a+1,b+1);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j])f[i][j]=max(f[i][j],f[i-1][j-1]+1);            
        }
    cout<<f[n][m]<<endl;
    
    return 0;
}
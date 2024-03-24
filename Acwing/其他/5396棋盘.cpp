#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/**
 * 5396棋盘
 * 二维差分
 * 主要还是用了奇数和偶数这个性质，操作的次数和奇偶性相关
*/
const int N=2005;
int a[N][N],b[N][N];
int n,m;

void insert(int x,int y,int x1,int y1,int c)
{
    b[x][y]+=c;
    b[x1+1][y]-=c;
    b[x][y1+1]-=c;
    b[x1+1][y1+1]+=c;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y,x1,y1;
        scanf("%d%d%d%d",&x,&y,&x1,&y1);
        insert(x,y,x1,y1,1);
    }   
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=b[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            cout<<a[i][j]%2;
        }
        cout<<endl;
    }
    return 0;
}
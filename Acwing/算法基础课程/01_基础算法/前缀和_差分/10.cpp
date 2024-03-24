#include<iostream>
using namespace std;
const int N=1e4+10;

int a[N][N];
int s[N][N];//前缀和数组
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[i][j]=a[i][j]+s[i][j-1]+s[i-1][j]-s[i-1][j-1];//计算前缀和

    while(q--)
    {
        //计算子区间的和
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int result=s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
        printf("%d\n",result);
    }
    
 
    return 0;
}
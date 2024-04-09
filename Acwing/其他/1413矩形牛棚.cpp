#include<iostream>
#include<algorithm>
using namespace std;
/**
 * 1413矩形牛棚
 * 单调栈
 * 参考直方图那个题
 * 131. 直方图中最大的矩形
*/
const int N=3010;
int n,m;
int g[N][N];//格子是否被破坏
int h[N][N];//当前格子上方没被破坏的格子数
int l[N],r[N];
int stk[N],top;//单调栈

int work(int b[])
{
    b[0]=b[m+1]=-1;
    top=0;
    stk[++top]=0;//把0放进去
    //处理左边比当前高度小的数字
    for(int i=1;i<=m;i++)
    {
       while(top&&b[stk[top]]>=b[i])top--;
       l[i]=stk[top];
       stk[++top]=i; 
    }

    top=0;
    stk[++top]=m+1;
    for(int i=m;i>=1;i--)
    {
        while(top&&b[stk[top]]>=b[i])top--;
        r[i]=stk[top];
        stk[++top]=i;
    }

    int res=0;
    for(int i=1;i<=m;i++)
        res=max(b[i]*(r[i]-l[i]-1),res);
    return res;

}

int main()
{
    int p;
    cin>>n>>m>>p;
    while(p--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x][y]=1;
    }

    //预处理
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!g[i][j])
                h[i][j]=h[i-1][j]+1;

    int res=0;
    for(int i=1;i<=n;i++)
        res=max(res,work(h[i]));
    cout<<res<<endl;
    return 0;
}
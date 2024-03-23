#include<iostream>
#include<algorithm>
using namespace std;
/**
 * 99激光炸弹
 * 没有注意题目的条件，会爆掉内存
 * 如果R过大超出了范围，在判断的时候将x,y设置为边界
 * if(x<N&&y<N)当炸弹超出目标的取值范围之后应该也是能达到的
 * res=max(res,s[x][y]-s[i-1][y]-s[x][j-1]+s[i-1][j-1]);  
*/
const int N=5010;
int s[N][N];
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        s[a+1][b+1]+=c;
    }

    //前缀和
    for(int i=1;i<=N-1;i++)
    {
        for(int j=1;j<=N-1;j++)
        {
            s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }

    if(m==0)
    {
        cout<<0<<endl;
        return 0;
    }

    int res=0;
    //枚举
    for(int i=1;i<N;i++) 
    {
        for(int j=1;j<N;j++)
        {
            
            int x=i+m-1,y=j+m-1;
            x=min(x,N-1),y=min(y,N-1);
            res=max(res,s[x][y]-s[i-1][y]-s[x][j-1]+s[i-1][j-1]);  
        }
    }  
    cout<<res<<endl;

    return 0;
}
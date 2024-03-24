#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

/**
 * 91.最短Hamilton路劲
 * 状态压缩
 * 1.输入
 * 2.初始化
 * 3.dp过程
*/
const int N=20,M=1<<N;
int m[N][N];
int f[M][N];
int n;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>m[i][j];

    memset(f,0x3f,sizeof(f));
    f[1][0]=0;//1表示经过第0个点

    for(int i=0;i<1<<n;i++)//也可以从2开始。10表示走第一个点，01表示第0个点
        for(int j=0;j<n;j++)
        {
            if(i>>j&1)//能够到道j点
            {
                for(int k=0;k<n;k++)
                    if(i>>k&1)
                    {   
                        if((i-(1<<j))>>k&1)
                            f[i][j]=min(f[i][j],f[(i-(1<<j))][k]+m[k][j]);
                    }
            }
        }

    //从1~n-1位置为1，0的位置上是0,得去除第0个点
    cout<<f[(1<<n)-1][n-1]<<endl;

    return 0;
}
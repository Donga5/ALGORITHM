#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/**
 * 291 蒙德里安的梦想
 * 状态压缩dp,朴素写法
*/
const int N=12,M=1<<N;
long long  f[N][M];
bool st[M];
int n,m;//行和列

int main()
{
    while(cin>>n>>m,n||m)
    {
        //预处理每一列的所有状态是否合法
        for(int i=0;i<1<<n;i++)
        {
            st[i]=true;
            int cnt=0;
            for(int k=0;k<n;k++)
            {
                if(i>>k&1)
                {
                    if(cnt&1)st[i]=false;//相当于cnt%2
                    cnt=0;
                }
                else cnt++;
            }
            if(cnt&1)st[i]=false;
        }


        memset(f,0,sizeof f);
        f[0][0]=1;
        for(int i=1;i<=m;i++)
            for(int j=0;j<1<<n;j++)
            {
                for(int k=0;k<1<<n;k++)
                {
                    if((k&j)==0&&st[k|j])f[i][j]+=f[i-1][k];
                }
            }
        cout<<f[m][0]<<endl;//第m列没有横向伸出横条的方案数
    }
    return 0;
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

/**
 * 291蒙德里安的梦想
 * 状态压缩dp,存储可用的状态
*/
typedef long long LL;
const int N=12,M=1<<N;
vector<int>a[M];//m个状态各自对应的合法状态
LL f[N][M];
bool st[M];
int n,m;

int main()
{
    while(cin>>n>>m,n||m)
    {
        for(int i=0;i<1<<n;i++)
        {
            st[i]=true;
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i>>j&1)
                {
                    if(cnt&1)st[i]=false;
                    cnt=0;
                }
                else cnt++;
            }
            if(cnt&1)st[i]=false;
        }

        //找到每种状态对应的合法状态
        for(int i=0;i<1<<n;i++)
        {
            a[i].clear();//记得清空
            for(int j=0;j<1<<n;j++)
                if((i&j)==0&&st[i|j])a[i].push_back(j);
        }
        memset(f,0,sizeof f);
        f[0][0]=1;
        for(int i=1;i<=m;i++)
            for(int j=0;j<1<<n;j++)
                for(auto k:a[j])
                    {
                        f[i][j]+=f[i-1][k];
                    }
        
        cout<<f[m][0]<<endl;
    }

    return 0;
}
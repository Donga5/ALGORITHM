#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 5. 多重背包问题 II
 * 多重背包的二进制优化，优化之后变为01背包,s的优化成logs背包
 * 共有2000件物品，每件物品最多拆分成log(2000)件物品 
 * 
*/
const int N=25000;
int v[N],w[N];
int f[N];

int main()
{
    int n,m;
    cin>>n>>m;

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int a,b,s;
        cin>>a>>b>>s;
        int k=1;
        //拆分并且打包成新的包
        while(k<=s)
        {
            cnt++;
            v[cnt]=k*a;
            w[cnt]=k*b;
            s-=k; 
            k*=2;
        }
        if(s)
        {
            cnt++;
            v[cnt]=s*a;
            w[cnt]=s*b;
        }
    }

    for(int i=1;i<=cnt;i++)
        for(int j=m;j>=v[i];j--)
            f[j]=max(f[j],f[j-v[i]]+w[i]);
    
    cout<<f[m];
    return 0;
}
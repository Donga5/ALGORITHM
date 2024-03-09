#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 888 求组合数1
*/
const int N=2010,mod=1e9+7;
int c[N][N];
typedef long long LL;

void init()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=i;j++)
            {
                if(!j)c[i][j]=1;
                else c[i][j]=(LL)(c[i-1][j]+c[i-1][j-1])%mod;
            }
    }
}

int main()
{
    init();
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",c[a][b]);
    }
    return 0;
}
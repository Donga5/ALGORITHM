#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

/**
 * 860染色法判定二分图
 * 注意这道题是无向图，存边的时候需要两条都存，所以一定要注意边的范围
 * 否则会出现数组越界
 * 
 * 类型题目：
 * 257. 关押罪犯
*/
const int N=1e5+10,M=N*2;
int h[N],e[M],ne[M],idx;
int n,m;
int color[N];

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool dfs(int u,int c)
{
    color[u]=c;

    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!color[j])
        {
            if(!dfs(j,3-c))
            {
                return false;
            }
        }
        else if(color[j]==c)
                return false;
        
    }
    return true;

}

int main()
{
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);
    }

    //可能图不是连通的
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(!color[i])
        {
            if(!dfs(i,1))
            {
                flag=false;
                break;
            }
        }
    }

    if(flag)puts("Yes");
    else puts("No");

    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 2069网络分析
 * 并查集
 * 一定要记得初始化
 * 合并时不创建新点，采用更新权值的方式
*/
const int N=1e4+10;
int p[N];
int d[N];
int n,m;

int find(int x)
{
    if(p[x]==x||p[p[x]]==p[x])return p[x];//当前点是根节点或者父节点是根节点
    int r=find(p[x]);//递归找到根节点
    d[x]+=d[p[x]];//保证节点的值正确
    p[x]=r;//路径压缩
    return r;
}


int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)p[i]=i;
    while(m--)
    {
        int t,a,b;
        scanf("%d%d%d",&t,&a,&b);
        if(t==1)
        {
            a=find(a),b=find(b);//变成对应联通块中根节点的编号
            if(a!=b)
            {
                d[a]-=d[b];
                p[a]=b;
            }
        }
        else 
        {
            a=find(a);
            d[a]+=b;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(i==find(i))printf("%d ",d[i]);
        else printf("%d ",d[i]+d[find(i)]);
    }
    puts("");
    return 0;
}
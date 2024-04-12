#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 2069网络分析
 * 并查集
 * 一定要记得初始化
 * 合并时创建新点，跟另一种方式差不多
*/
const int N=1e4+10;
int p[2*N];
int d[2*N];
int n,m;
int cnt=0;

int find(int x)
{
    if(p[x]==x||p[p[x]]==p[x])return p[x];//当前点是根节点或者父节点是根节点
    int r=find(p[x]);//递归找到根节点
    d[x]+=d[p[x]];//保证节点的值正确
    p[x]=r;//路径压缩
    return r;
}

void add_root(int a,int b)
{
    cnt++;
    p[cnt]=cnt;
    p[find(a)]=cnt;
    p[find(b)]=cnt;
}

int main()
{
    cin>>n>>m;
    cnt=n;
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
                add_root(a,b);
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
#include<iostream>
using namespace std;

/**
 * 837:连通块中点的数量
 * 并查集，动态地维护每个集合的数量
*/
const int N=1e5+10;
int p[N],sz[N];

int find(int x)//查找一个节点的父亲节点+路径压缩
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        //初始化
        p[i]=i;//这里初始化的时候要注意
        sz[i]=1;
    }

    while(m--)
    {
        char op[3];
        int a,b;
        scanf("%s",op);
        if(op[0]=='C')
        {
            scanf("%d%d",&a,&b);
            if(find(a)==find(b))continue;//避免sz重复增加
            sz[find(b)]+=sz[find(a)];
            p[find(a)]=p[b];
        }
        else if(op[1]=='1')
        {
            scanf("%d%d",&a,&b);
            if(find(a)==find(b))puts("Yes");
            else puts("No");
        }
        else{
            scanf("%d",&a);
            printf("%d\n",sz[find(a)]);
        }
    }
    return 0;
}
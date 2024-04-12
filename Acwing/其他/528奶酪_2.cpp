#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

/**
 * 528奶酪
 * 并查集，更简单的写法，不需要进行排序
 * 注意，查找当前的节点属于哪个集合当中的时候，最好还是用find函数
 * 不要用p[x]，虽然路径压缩已经了修改了p[x],如果中间修改了根节点，p[x]可能已经不是最新的了
 * 修改用p[x]
*/
const int N=1010;
int p[N];
int n,h,r;
typedef long long LL;

struct Pos
{
    int x,y,z;
}pp[N];

int find(int x)
{
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>h>>r;
        for(int i=0;i<=n+1;i++)p[i]=i;
        for(int i=1;i<=n;i++)
        {
            int x,y,z;  
            scanf("%d%d%d",&x,&y,&z);
            pp[i]={x,y,z};

            if(pp[i].z<=r)p[find(i)]=find(0);
            if(pp[i].z+r>=h)p[find(i)]=find(n+1);
        }

        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                LL dx=pp[i].x-pp[j].x;
                LL dy=pp[i].y-pp[j].y;
                LL dz=pp[i].z-pp[j].z;
                if(dx*dx+dy*dy+dz*dz<=4*(LL)r*r)
                    p[find(i)]=find(j);
            }
        if(find(0)==find(n+1))puts("Yes");
        else puts("No");
    }
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 528奶酪，并查集
 * 注意这里是需要进行排序的
*/
const int N=1010;
typedef long long LL;
struct Pos
{
    int x,y,z;
    bool operator <(const Pos& p)const 
    {
        return z<p.z;
    }
}pos[N];
int n,h,r;
int p[N];



int find(int x)
{
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}

bool check(int i,int j)
{
    LL d=(LL)(pos[i].x-pos[j].x)*(pos[i].x-pos[j].x)+(LL)(pos[i].y-pos[j].y)*(pos[i].y-pos[j].y) \
        +(LL)(pos[i].z-pos[j].z)*(pos[i].z-pos[j].z);
    return d<=(LL)(2*r)*(2*r);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>h>>r;
        for(int i=0;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            pos[i]={x,y,z};
        }
        sort(pos,pos+n);

        for(int i=0;i<n;i++)
        {
            p[i]=i;
        }

        //合并
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                if(check(i,j))
                {
                    if(find(i)==find(j))continue;
                    p[find(i)]=find(j);
                }
            }
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            if(pos[i].z>r)continue;//必须挨着地面的一个开始找
            int t=find(i);
            if(pos[t].z+r>=h)
            {
                flag=true;
                break;
            }
        }
        if(flag)puts("Yes");
        else puts("No");
    }
    

    return 0;
}
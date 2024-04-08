#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/**
 * 4957飞机降落
 * 暴搜
*/
const int N=10;
struct Plane
{
    int t,d,l;
}p[N];
bool st[N];
int n;

int dfs(int u,int last)
{
    if(u==n)return true;
    for(int i=0;i<n;i++)
    {   
        int t=p[i].t,d=p[i].d,l=p[i].l;
        if(!st[i]&&t+d>=last)
        {
            st[i]=true;
            if(dfs(u+1,max(last,t)+l))return true;
            st[i]=false;
        }
    }
    return false;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int t,d,l;
            cin>>t>>d>>l;
            p[i]={t,d,l};
        }
        memset(st,false,sizeof(st));
        if(dfs(0,0))puts("YES");
        else puts("NO");
    }
    
    return 0;
}
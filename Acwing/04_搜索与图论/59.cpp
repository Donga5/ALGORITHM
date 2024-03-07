#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

/**
 * 861 二分图的最大匹配
 * 匈牙利算法
 * 算法理解：
 * st数组才是精髓
 * 
 * 1.如果你每次不把st重新置为false，那剩下的人一看到前面的妹子st已经为true，
 * 不去让妹子的对象换掉这个妹子，直接就放弃了，会影响最后结果。
 * 2.对面没有匹配或者是对方已经匹配了，就让已经和对方匹配的那个人尝试重新进行匹配。
 * 如果尝试失败,match也不会进行改变，而是直接返回false
*/
const int N=510,M=1e5+10;
int match[N];
int h[N],e[M],ne[M],idx;
int n1,n2,m;
bool st[N];

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool dfs(int u)
{
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!st[j])
        {
            st[j]=true;
            if(match[j]==0||dfs(match[j]))
            {                             
                match[j]=u;
                return true;
            }
        }
    }
    return false;
}

int main()
{   
    cin>>n1>>n2>>m;
    memset(h,-1,sizeof(h));

    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }

    int res=0;
    for(int i=1;i<=n1;i++)
    {
        memset(st,false,sizeof(st));//每次左边开始匹配的时候都清空右边的状态
        if(dfs(i))res++;
    }

    cout<<res<<endl;

    return 0;
}
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/**
 *846 树的重心 
  树可以看作是一种特殊的图，是一种无向无环连通图
  使用邻接表来进行存储.这样的好处是从任意一点都能开始进行搜索
*/
const int N=1e5+10,M=2*N;
int n;
bool st[N];//一般每个节点访问一次

int h[N],e[M],ne[M],idx;//h表示n个单链表的头节点, e,ne,idx是单链表实现

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx,idx++;//插到a相关的链表上
}

// void dfs(int u)
// {
//     st[u]=true;
//     for(int i=h[u];i!=-1;i++)
//     {
//         int j=e[i];//节点编号
//         dfs(j);
//     }
// }


int ans=N;

//返回以u为根的树的顶点数
int dfs(int u)
{
    st[u]=true;
    int sum=1,res=0;//res表示删除当前节点后，当前节点的子树点数，以及其他联通块点数的最大值
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!st[j])
        {
            int s=dfs(j);
            res=max(res,s);
            sum+=s;//加上当前子树的点数
        }
    }

    res=max(res,n-sum);//删除当前重心中的最大联通块
    ans=min(ans,res);//求得全局最小值
    
    return sum;
}


 
int main()
{
    //链表头初始化
    memset(h,-1,sizeof h);
    cin>>n;
    int m=n-1;
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);//将树看成无向图
    }

    dfs(1);
    cout<<ans<<endl;

    return 0;
}
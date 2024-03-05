#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/**
 *846 树的重心 
  树可以看作是一种特殊的图，是一种无向无环连通图
  使用邻接表来进行存储
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

int dfs(int u)
{

}



int main()
{
    //链表头初始化
    memset(h,-1,sizeof h);
    cin>>n;
    int m=n;
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);//将树看成无向图
    }

    return 0;
}
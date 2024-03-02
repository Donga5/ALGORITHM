#include<iostream>
using namespace std;

/**
 * 835 Trie字符串统计
 * 并查集
*/
const int N=1e5+10;
int p[N];//记录对应节点的父节点，默认根节点p[i]=i;

int find(int x)//查找父节点+路径压缩
{
    if(p[x]!=x)p[x]=find(p[x]); //递归+路径压缩
    return p[x];
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++)p[i]=i;
    while(m--)
    {
        char op[2];//避免使用char对应scanf输入问题
        int a,b;
        scanf("%s%d%d",op,&a,&b);
        if(op[0]=='M')
        {
            if(find(a)!=find(b))p[find(a)]=find(b);//将a的根节点的父亲节点指向b的根节点
        }
        else
        {
            if(find(a)==find(b))puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
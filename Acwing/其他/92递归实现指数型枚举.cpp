#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/**
 * 92递归实现指数型枚举
 * 一定要注意搜索的是什么
*/
const int N=16;
int st[N];
int n;

void dfs(int u)
{
    if(u>n)
    {
        for(int i=1;i<=n;i++)
            if(st[i])printf("%d ",i);
        puts("");
        return ;
    }
    st[u]=0;//选择这个数
    dfs(u+1);
    st[u]=1;//不选这个数
    dfs(u+1);
}

int main()
{
    cin>>n;
    dfs(1);//枚举的每一位数是否选择
    return 0;
}
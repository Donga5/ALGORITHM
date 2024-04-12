#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/**
 * 92递归实现指数型枚举
 * 使用位运算
 * 一定要注意搜索的是什么
*/
const int N=16;
int n;
void dfs(int u,int state)
{
    if(u==n)
    {
        for(int i=0;i<n;i++)
            if(state>>i&1)//拿到最后一位
                printf("%d ",i+1);
        puts("");
        return ;
    }
    dfs(u+1,state);//不选，则不用变
    dfs(u+1,state|(1<<u));//选，对应的二进制为赋值为1
}

int main()
{
    cin>>n;
    dfs(0,0);
    return 0;
}
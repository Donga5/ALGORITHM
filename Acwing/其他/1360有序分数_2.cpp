#include<iostream>
using namespace std;
/**
 * 1360 有序分数
 * Stern–Brocot tree
 * 性质:
 * 1.得到的都是有序地
 * 2.中序遍历可以得到有序序列
 * 递归实现
*/
int n;

void dfs(int a,int b,int c,int d)
{
    if(b+d>n)return ;
    dfs(a,b,a+c,b+d);
    printf("%d/%d\n",a+c,b+d);
    dfs(a+c,b+d,c,d);
}

int main()
{
    cin>>n;
    puts("0/1");
    dfs(0,1,1,1);
    puts("1/1");

    return 0;
}
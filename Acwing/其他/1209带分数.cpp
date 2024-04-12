#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
/**
 * 1209带分数
 * dfs+剪枝
 * 转化为没有分数的等式，只需要枚举a和c，然后计算出b判断是否符合条件
*/
const int N=20;
int st[N],back[N];//保存所有的状态
int n;
int res=0;

bool check(int a,int c)
{
    int b=(long long)n*c-(long long)c*a;
    if(!b||!a||!c)return false;
    memcpy(back,st,sizeof(st));
    while(b)
    {
        int x=b%10;
        b/=10;
        //某一位上是0或者已经用过这一位
        if(!x||back[x])return false;
        back[x]=true;
    }
    //检查所有数字是否都已经被使用够
    for(int i=1;i<=9;i++)
        if(!back[i])return false;
    return true;
}


void dfs_c(int u,int a,int c)
{
    if(check(a,c))res++;
    
    for(int i=1;i<=9;i++)
    {
        if(!st[i])
        {
            st[i]=true;
            dfs_c(u+1,a,c*10+i);
            st[i]=false;
        }
    }
}

void dfs_a(int u,int a)
{
    if(a>=n)return ;//边界
    if(a)dfs_c(u,a,0);

    for(int i=1;i<=9;i++)
    {
        if(!st[i])
        {
            st[i]=1;
            dfs_a(u+1,a*10+i);
            st[i]=0;
        }
    }
    
}

int main()
{
    cin>>n;
    dfs_a(0,0);//u表示枚举的是位置
    cout<<res<<endl;
    return 0;
}
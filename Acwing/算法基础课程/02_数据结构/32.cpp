#include<iostream>
#include<cstring>
using namespace std;

/**
 * 840:模拟散列表
 * 哈希表
 * 使用链地址法来处理冲突
*/
const int N=1e5+3;//一般使用质数冲突的次数更少
int h[N],e[N],ne[N],idx;

void insert(int x)
{
    int k=(x%N+N)%N;//c++中负数对于整数取模是负数，所以要这样写使得正数和负数都能映射到同样的区间
    e[idx]=x,ne[idx]=h[k],h[k]=idx++;//对于每个位置的冲突统一用一个链表来进行处理
}
bool query(int x)
{
    int k=(x%N+N)%N;
    for(int i=h[k];i!=-1;i=ne[i])
        if(e[i]==x)
            return true;
    return false;
}
int main()
{
    int n;
    cin>>n;
    memset(h,-1,sizeof h);

    char op[2];int x;
    while(n--)
    {
        scanf("%s%d",op,&x);
        if(op[0]=='I')insert(x);
        else
        {
            if(query(x))puts("Yes");
            else puts("No");
        }
        
    }
    return 0;
}

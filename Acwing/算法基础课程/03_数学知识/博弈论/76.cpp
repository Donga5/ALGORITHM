#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<cstring>
using namespace std;

/**
 * 893. 集合-Nim游戏 
*/
const int N=105,M=1e5+10;;
int s[N],f[M];//s表示取数的集合，f[i]表示每个数的sg的值
int n,m;

int sg(int x)
{
    if(f[x]!=-1)return f[x];//已经计算过就不重复计算

    unordered_set<int>S;
    for(int i=0;i<m;i++)
    {
        int sum=s[i];
        if(x>=sum)S.insert(sg(x-sum));//递归计算能够达到节点的sg的值
    }

    //从相连节点的Sg值中，选出最小的没有出现的自然数的操作
    for(int i=0;;i++)
        if(!S.count(i))
            return f[x]=i;

}

int main()
{
    cin>>m;
    for(int i=0;i<m;i++)cin>>s[i];

    memset(f,-1,sizeof f);

    cin>>n;
    int res=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        res^=sg(x);
    }
    if(res)puts("Yes");
    else puts("No");

    return 0;
}
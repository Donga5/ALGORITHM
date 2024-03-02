#include<iostream>
using namespace std;
/**
 * 字符串哈希：
 * 从k进制的角度来把一个字符串看成一个数字
 * 使用unsigned long long 会溢出，相当于是对pow(2,64)去余
 * 经验值:P为131或者1331
 * 然后Q为2d的64次方
 * 
 * 主要用来快速判断两个字符串是否相等
*/
typedef unsigned long long ULL;
const int N=1e5+10,P=131;
int n,m;
char str[N];
ULL h[N],p[N];//h表示字符串前缀的哈希值,p表示当前累计的次幂

ULL get(int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}

int main()
{
    cin>>n>>m;
    scanf("%s",str+1);//字符串从1的位置开始读入

    //求出每个前缀的哈希
    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+str[i];
    }
    
    while(m--)
    {
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(get(l1,r1)==get(l2,r2))
        {
            puts("Yes");
        }
        else puts("No");
    }
    return 0;
}
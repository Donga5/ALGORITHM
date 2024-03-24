#include<iostream>
using namespace std;

/**
 * 利用lowbit操作求二进制中一的个数
 *  
*/
//返回的是从x的二进制的高位开始的最后一位1和后面的0组成的数
int lowbit(int x)
{
    return x&-x;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        scanf("%d",&x);
        int res=0;
        while(x)x-=lowbit(x),res++;
        printf("%d ",res);
    }

    return 0;
}
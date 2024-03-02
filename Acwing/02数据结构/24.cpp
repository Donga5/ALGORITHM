#include<iostream>
using namespace std;


/**
 * 830单调栈
 * 当数量在1e6的时候，输入尽量使用scanf和printf时间更短
 * 基本思路：
 * 当i>j，而且a[i]<a[j]，这时候a[j]肯定是不在答案中的，所以要动态维护一个栈，保持栈中的数单调递增
*/
const int N=1e6+10;
int a[N],tt;//tt指向栈顶元素
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        while(tt&&a[tt]>=x)tt--;//注意是>=等于情况也需要进行删除
        if(tt)printf("%d ",a[tt]);
        else printf("-1 ");
        //将x入栈
        a[++tt]=x;
    }

    return 0;
}
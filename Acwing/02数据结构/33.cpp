#include<iostream>
#include<cstring>
using namespace std;

/**
 * 840 模拟散列表
 * 哈希表
 * 开放寻址法
 * N一般选择一个质数，一般可以编写一段求质数的代码来进行求解
*/
const int N=2e5+3,null=0x3f3f3f3f;//选择一个不在当前数值范围内的数字
int h[N];

//如果不存在，则返回应该插入的位置，如果存在，返回位置
int find(int x)
{
    int k=(x%N+N)%N;
    while(h[k]!=null&&h[k]!=x)
    {
        k++;
        if(k==N)k=0;//到达末尾从头开始查找
    }
    return k;
}
int main()
{
    int n;
    cin>>n;
    memset(h,0x3f,sizeof h);//注意memset按照字节进行赋值
    
    char op[2];
    int x;
    
    while(n--)
    {
        scanf("%s%d",op,&x);
        int k=find(x);
        if(op[0]=='I')h[k]=x;
        else
        {
            if(h[find(x)]==null)puts("No");
            else puts("Yes");
        }
    }
     
    return 0;
} 
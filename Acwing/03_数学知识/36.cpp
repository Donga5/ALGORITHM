#include<iostream>
using namespace std;

/**
 * 867 分解质因数
 * 质因数介绍，请搜索notion 
*/

void divide(int n)
{
    for(int i=2;i<=n/i;i++)
        if(n%i==0)
        {
            int s=0;//表示指数
            while(n%i==0)
            {
                n/=i;
                s++;
            }
            printf("%d %d\n",i,s);
        }
    if(n>1) printf("%d %d\n",n,1);//本身是个质数，到这里会进行输出
    puts(" ");
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        divide(x);
    }
    return 0;
}
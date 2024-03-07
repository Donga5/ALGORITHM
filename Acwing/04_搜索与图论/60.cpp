#include<iostream>
using namespace std;

/**
 * 873.欧拉函数
 * 证明过程参考题解
*/
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        
        int res=a;
        for(int i=2;i<=a/i;i++)
            if(a%i==0)
            {
                res=res/i*(i-1);//套公式
                while(a%i==0)a=a/i;
            }
        if(a>1)res=res/a*(a-1);
        cout<<res<<endl;
    }
    return 0;
}
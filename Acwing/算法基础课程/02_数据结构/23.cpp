#include<iostream>
#include<string>
using namespace std;

/**
 * 829 模拟栈：使用数组来模拟栈
 * tt指向栈顶元素的下一个位置
*/
const int N=1e6+10;
int q[N],tt=1;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string op;
        cin>>op;
        if(op=="push")
        {
            int x;
            cin>>x;
            q[tt++]=x;
        }
        else if(op=="pop")
        {
            --tt;
        }
        else if(op=="empty")
            cout<<(tt>1?"NO":"YES")<<endl;
        else 
            cout<<q[tt-1]<<endl;
    }
    return 0;
}
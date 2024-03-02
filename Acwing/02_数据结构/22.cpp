#include<iostream>
using namespace std;

/**
 * 829 模拟队列
 * 
 * 
 * hh<tt说明队列为空
 * hh=tt说明队列中只有一个元素,

*/
const int N=1e6+10;
int q[N],hh,tt=-1;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string op;
        cin>>op;
        int x;
        if(op=="push")
        {
            cin>>x;
            q[++tt]=x;
        }
        else if(op=="pop")++hh;
        else if(op=="empty")
            cout<< (tt>=hh?"NO":"YES")<<endl;
        else
            cout<<q[hh]<<endl;
    }

    return 0;
}
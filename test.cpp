#include<iostream>
using namespace std;
int main()
{
    int a=(1<<30)-1+(1<<30);
    cout<<a<<endl;
    //输出a每一位
    for(int i=31;i>0;i--)cout<<(a>>i&1);
    cout<<endl;

    a=a+4;
    cout<<a<<endl;
    for(int i=31;i>0;i--)cout<<(a>>i&1);
    cout<<endl;
}
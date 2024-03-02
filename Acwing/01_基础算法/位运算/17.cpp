#include<iostream>
using namespace std;

/**
 * 求一个负数的二进制表示
 *  
*/

int main()
{
    int x=-10;
    int i;
    for(i=31;i>=0;i--)
        cout<<(x>>i&1);
    cout<<endl;
    for(i=31;i>=0;i--)
        cout<<(10>>i&1);
    cout<<endl;

    return 0;
}
#include<iostream>
#include<bitset>
using namespace std;

/**
 * anyone()判断是否至少有一个1
 * none()判断是否全为0
 * set(k,v) 将第k位变成v
*/

int main(int argc, char const *argv[])
{
    bitset<100> b;
    b[0]=1;
    b[2]=1;
    cout<<b.count()<<endl;//返回1的个数

    b.set(4);
    cout<<b[4]<<endl;

    b.reset(4);
    cout<<b[4]<<endl;

    

    return 0;
}

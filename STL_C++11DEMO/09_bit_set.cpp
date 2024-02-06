#include<iostream>
#include<bitset>
using namespace std;

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

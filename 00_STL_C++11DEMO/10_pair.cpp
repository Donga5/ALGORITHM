#include<iostream>
#include<utility> //pair在这个头文件中
/**
 * 支持排序，先按照第一个关键字进行排序，然后第二个关键字排序
 * 适用于有两个属性，但是需要按照第一个关键字来排序的场景 
*/
using namespace std;
void demo1()
{
    pair<string,int>p1("abc",10);
    pair<string,int>p2=make_pair("def",20);
    pair<string,int>p4{"hello",2};//c++11
    auto p3=p1;
    
    cout<<p1.first<<" "<<p2.second<<endl;
    
}
int main(int argc, char const *argv[])
{
    demo1();
    return 0;
}

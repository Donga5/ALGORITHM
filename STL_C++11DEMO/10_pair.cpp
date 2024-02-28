#include<iostream>
#include<utility> //pair在这个头文件中
using namespace std;
void demo1()
{
    pair<string,int>p1("abc",10);
    pair<string,int>p2=make_pair("def",20);
    pair<string,int>p4{"hello",2};
    auto p3=p1;
    
    cout<<p1.first<<" "<<p2.second<<endl;
    
}
int main(int argc, char const *argv[])
{
    demo1();
    return 0;
}

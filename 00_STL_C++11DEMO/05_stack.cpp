#include<iostream>
#include<stack>
using namespace std;

/**
 * stack 的基本操作和声明和queue类似
*/
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    cout<<s.top()<<endl;//栈顶元素
    s.pop();
    cout<<s.top()<<endl;
    return 0;
}
#include<iostream>
#include<string>
using namespace std;

/**
 * size
 * empty()
 * clear
 * substr()
*/
int main()
{
    string a="abs";
    
    a+="111";//支持字符串拼接
    cout<<a<<endl;
    
    cout<<a.substr(1,2);//第一个参数为子串的起始下标,第二个为子串的长度 
    puts(" ");
    cout<<a.substr(1);//返回从1开始的所有字符串

    return 0;
}
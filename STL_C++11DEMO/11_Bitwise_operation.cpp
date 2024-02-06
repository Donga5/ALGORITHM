#include<iostream>
using namespace std;
void demo1()
{
    int a = 60;  // 0011 1100
    int b = 13;  // 0000 1101
    int c = a & b;  // 0000 1100  AND(与)运算

    c=a|b;
    cout<<c<<endl;// 0011 1101  OR

    c=a^b;
    cout<<c<<endl;// 0011 0001  XOR(异或)

    c=~a;
    cout<<c<<endl;// 1100 0011  NOT(取反)

    a=4;
    cout<<(a<<1);//左移1位 8

}

//常用操作
void demo2()
{
    //取到一个数(二进制，正数的原，反，补都相同）的第k位 a>>k&1
    //从右开始数，第0位是最右边的一位
    int a=13;//0000 1101
    cout<<(a>>3 & 1)<<endl;

    /***
     * 
     * 返回x的二进制的最后一位1
     * x&-x
     * 由于使用的是补码 -x其实就是(~x+1)
    */
    
    a=13;//0000 1101
    cout<<(a&-a)<<endl;
}

int main(int argc, char const *argv[])
{
    // demo1();
    demo2();
    return 0;
}

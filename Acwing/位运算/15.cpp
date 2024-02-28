#include<iostream>
using namespace std;

/**
 * 求正整数的二进制表示的第k为数是几，从低位开始是第0位
 * 
*/
int main()
{
    int n=10;
    for(int k=3;k>=0;k--)cout<<(n>>k&1);
    return 0;
}
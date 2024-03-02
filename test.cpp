#include<iostream>
using namespace std;
int main()
{
    unsigned long long x = -1; // -1在无符号整数类型中表示最大值
    std::cout << x << std::endl; // 输出4294967295，即2^32-1
    x += 1;
    std::cout << x << std::endl; // 输出0，因为4294967295+1回绕到0
    return 0;
    return 0;
}
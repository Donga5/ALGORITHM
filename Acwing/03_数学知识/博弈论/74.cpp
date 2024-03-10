#include<iostream>
#include<algorithm>

using namespace std;

/**
 * 891.Nim游戏
 * 相关证明查看题解
 * 结论：异或值为不为0则是先手必胜
*/
int main()
{
    int n;
    cin>>n;
    int res=0;
    while(n--)
    {
        int x;
        cin>>x;
        res^=x;
    }
    if(res)puts("Yes");
    else puts("No");

    return 0;
}
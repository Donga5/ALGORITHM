#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 892 台阶-nim游戏
 * 只需要处理奇数台阶上的数
*/


int main()
{
    int n;
    cin>>n;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(i%2)
        {
            res=res^x;
        }
    }
    
    if(res)puts("Yes");
    else puts("No");
    return 0;
}
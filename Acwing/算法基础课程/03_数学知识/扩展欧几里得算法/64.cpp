#include<iostream>
using namespace std;

/**
 * 877.扩展欧几里得算法
*/
const int N=1e5+10;

int exgcd(int a,int b,int &x, int &y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y=y-(a/b)*x;
    return d;
}



int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b,x,y;
        scanf("%d%d",&a,&b);
        exgcd(a,b,x,y);
        printf("%d %d \n",x,y);
    }
    return 0;
}
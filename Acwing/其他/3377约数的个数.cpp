#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 3377约数的个数
*/
int n;

int get(int x)
{
    int res=1;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
        {
            int s=0;
            while(x%i==0)
            {
                x/=i;
                s++;
            }
            res*=(s+1);
        }
    if(x>1)res*=2;
    return res;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",get(x));
    }
    
    return 0;
}
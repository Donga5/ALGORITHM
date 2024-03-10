#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 890 能被整除的数
 * 利用了容斥原理
*/
const int N=20;
int n,m;
int p[N];//表示能够被i整除的数字
typedef long long LL;

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>p[i];

    int res=0;
    for(int i=1;i<1<<m;i++)
    {
        int t=1,s=0;//s统计当前选中的质数的个数,t表示质数的乘积
        for(int j=0;j<m;j++)
        {
            if(i>>j&1)
            {
                if((LL)t*p[j]>n)
                {
                    t=-1;
                    break;
                }
                t*=p[j];s++;
            }
        }
        //如果t=-1，说明这种组合是不行的
        if(t!=-1)
        {
            if(s%2)res+=n/t;
            else res-=n/t;
        }
    }
    cout<<res<<endl;

    return 0;
}
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

/**
 * 1221四平方和
 * 知道了a,b,c之后 d可以计算出来
 * 
 * 哈希
*/
const int N=5e6+10;
int h[N];
int n;

int main()
{
    cin>>n;
    memset(h,-1,sizeof(h));
    //预处理:c*c+d*d
    for(int c=0;c*c<=n;c++)
        for(int d=c;c*c+d*d<=n;d++)
        {
            int t=c*c+d*d;
            if(h[t]==-1)//如果有冲突，只保存最小的就行
            {
                h[t]=c;
            }
        }
    for(int a=0;a*a<=n;a++)
        for(int b=a;a*a+b*b<=n;b++)
        {
            int s=a*a+b*b;
            if(h[n-s]==-1)continue;
            if(h[n-s]<b)continue;
            int d=sqrt(n-s-h[n-s]*h[n-s]);
            printf("%d %d %d %d\n",a,b,h[n-s],d);
            return 0;
        }
    return 0;
}
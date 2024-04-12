#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

/***
 * 1221四平方和
 * 利用二分来查找c*c+d*d的值
*/
const int N=5e6+10;
int n;
int cnt;

struct Node
{
    int c,d;
    int s;
    bool operator < (const struct Node & p)const 
    {
        if(s!=p.s)return s<p.s;
        else return c<p.c;
    }
}arr[N];


int main()
{
    cin>>n;
    for(int c=0;c*c<=n;c++)
        for(int d=c;c*c+d*d<=n;d++)
        {
            int s=c*c+d*d;
            arr[cnt++]={c,d,s};
        }
    
    sort(arr,arr+cnt);

    for(int a=0;a*a<=n;a++)
        for(int b=a;a*a+b*b<=n;b++)
        {
            int s=n-a*a-b*b;
            int l=0,r=cnt-1;//注意这里r的边界
            while(l<r)
            {
                int mid=(l+r)>>1;
                if(arr[mid].s>=s)r=mid;
                else l=mid+1;
            }
            if(arr[r].s==s)
            {
                printf("%d %d %d %d\n",a,b,arr[r].c,arr[r].d);
                return 0;
            }
        }
    return 0;
}
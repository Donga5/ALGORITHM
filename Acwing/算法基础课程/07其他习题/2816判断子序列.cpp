#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+10;
int a[N];
int b[N];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<m;i++)scanf("%d",&b[i]);

    int i=0,j=0;
    for(;i<m;i++)
    {
        if(b[i]==a[j])j++;
    }
    if(j>=n)puts("Yes");
    else puts("No");
    
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 1265数星星
 * 树状数组必须从1开始
 * 基本思路:由于点是按层给出的，所以每个星星i，前面的星星的y值都比当前i要小。只需要判断前面有多少个星星的x小于星星i
*/
const int N=32010;
int n;
int tr[N],ans[N];

int lowbit(int x)
{
    return x&-x;
}
void add(int x)
{
    for(int i=x;i<N;i+=lowbit(i))tr[i]+=1;
}
int query(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=tr[i];
    return res;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++;
        ans[query(x)]++;
        add(x);        
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<endl;

}

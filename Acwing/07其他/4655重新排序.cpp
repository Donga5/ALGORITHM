#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
/**
 * 4655重新排序
 * 利用差分求出每个位置的覆盖次数，求出和
 * 然后将原数组和差分数组分别按照从小到大顺序进行排序。然后求出最大值
*/
const int N=1e5+10;
typedef long long LL;
typedef pair<int,int> PIT;
int n,m;
int a[N];
int b[N];


void insert(int l,int r,int c)
{
    b[l]+=c;
    b[r+1]-=c;
}

int main()
{
    LL res1=0,res2=0;
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    cin>>m;
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        insert(l,r,1);
    }
    //求出每个位置的覆盖次数
    for(int i=1;i<=n;i++)b[i]+=b[i-1];

    for(int i=1;i<=n;i++)res1+=(LL) a[i]*b[i];

    sort(a+1,a+n+1);
    sort(b+1,b+n+1);

    for(int i=1;i<=n;i++)
    {
        res2+=(LL)a[i]*b[i];
    }
    cout<<res2-res1<<endl;

    return 0;
}

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/**
 * 1236递增三元组
 * 枚举b[i]比较好，对于b[i],找到的a[i]数量和c[i]数量可以直接进行相乘
 * 本题中注意的点
 * 1.由于数据范围比较小，可以用前缀和
 * 2.前缀和最好是都是>1的数，边界问题较少,本题可以将所有数值+1(因为比较的是相对大小)
*/
typedef long long LL;
const int N=1e5+10;
int a[N],b[N],c[N];
int as[N],cs[N];//记录比b[i]小的数字在a中出现的次数
int cnt[N],s[N];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]++;
    for(int j=1;j<=n;j++)scanf("%d",&b[j]),b[j]++;
    for(int i=1;i<=n;i++)scanf("%d",&c[i]),c[i]++;

    //预处理a[i]
    for(int i=1;i<=n;i++)cnt[a[i]]++;
    for(int i=1;i<N;i++)s[i]=s[i-1]+cnt[i];
    for(int i=1;i<=n;i++)as[i]=s[b[i]-1];

    memset(cnt,0,sizeof(cnt));
    memset(s,0,sizeof(s));
    
    for(int i=1;i<=n;i++)cnt[c[i]]++;
    for(int i=1;i<N;i++)s[i]=s[i-1]+cnt[i];
    for(int i=1;i<=n;i++)cs[i]=s[N-1]-s[b[i]];

    LL res=0;
    for(int i=1;i<=n;i++)
    {
        res+=(LL)as[i]*cs[i];
    }
    cout<<res<<endl;

    return 0;
}
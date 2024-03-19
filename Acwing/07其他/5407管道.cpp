#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/**
 * 5407管道
 * 注意点:
 * 1.考虑数据范围,尤其是极端情况下
 * 2.注意区间合并这里是离散化的情况，和连续的情况不同
 * 3.注意数据范围会爆掉int
*/
const int N=1e5+10;
int n,len;
typedef long long LL;
typedef pair<int,int> PIT;
int l[N],s[N];

//true 不能完全覆盖
bool check(int mid)
{
    vector<PIT>a;
    for(int i=0;i<n;i++)
    {
        if(s[i]>mid)continue;
        else if(s[i]==mid)a.push_back({l[i],l[i]});
        else
        {
            a.push_back({max((LL)l[i]-(mid-s[i]),(LL)1),min((LL)l[i]+mid-s[i],(LL)len)});
        }
    }

    sort(a.begin(),a.end());

    if(a[0].first!=1)return true;//没有覆盖最左端
    int r=a[0].second;
    for(int i=1;i<a.size();i++)
    {
        //注意这里是离散化的这种情况也可以r+1==a[i].first
        if(r+1 >= a[i].first)r=max(r,a[i].second);//中间有断开区域
        else return true;
    }
    
    if(r==len)return false;
    return true;

}

int main()
{
    cin>>n>>len;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&l[i],&s[i]);
    }

    int l=0,r=2e9;
    while(l<r)
    {
        int mid=(LL)l+r>>1;//这里当l和r取值靠近2e9的时候，中间计算结果会爆掉int
        if(check(mid))l=mid+1;
        else r=mid;
        // printf("%d %d\n",l,r);
    }
    cout<<l<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int>PIT;

const int N=110;
int n;
int a[N],s[N],l[N];
/**
 * 1262 鱼塘钓鱼
 * 使用堆来进行实现
*/

int work(int m,int T)
{
    priority_queue<PIT>q;//大根堆
    for(int i=1;i<=m;i++)q.push({a[i],i});
    int res=0;
    for(int i=1;i<=T&&!q.empty();i++)
    {   
        auto t=q.top();
        q.pop();
        res+=t.first;
        t.first-=s[t.second];
        if(t.first>=0)q.push(t);//循环的判断条件中只要不是0就都判断为true，包括负数
    }
    return res;
}


int main()
{
    int T;
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&s[i]);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&l[i]);
        l[i]+=l[i-1];
    }
    scanf("%d",&T);
    
    int res=0;
    for(int i=1;i<=n;i++)
    {
        res=max(res,work(i,T-l[i]));
    }
    cout<<res<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>

using namespace std;
/**
 * 1238日志统计
 * 双指针
*/
const int N=1e5+10;
typedef pair<int,int> PIT;
PIT logs[N];
int cnt[N];
bool hot[N];
int n;


int main()
{
    int d,k;
    cin>>n>>d>>k;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        logs[i]={a,b};
    }
    sort(logs,logs+n);

    for(int i=0,j=0;j<n;j++)
    {
        int id=logs[j].second;
        cnt[id]++;
        while(logs[j].first-logs[i].first>=d)
        {
            cnt[logs[i].second]--;
            i++;
        }
        if(cnt[id]>=k)hot[id]=true;
    }

    for(int i=0;i<=1e5;i++)
        if(hot[i])
            cout<<i<<endl;

    return 0;
}

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

/**
 * 906 区间分组 
 *  基于贪心算法
*/
const int N=1e5+10;
struct Range
{
    int l,r;
}ranges[N];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ranges[i]={a,b};
    }

    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<n;i++)
    {
        auto t=ranges[i];
        if(q.empty()||q.top()>t.l)q.push(t.r);
        else
        {
            q.pop();
            q.push(t.r);
        }
    }
    cout<<q.size()<<endl;

    return 0;
}
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
/**
 * 148 合并果子
*/
int main()
{
    priority_queue<int,vector<int>,greater<int>>q;
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        q.push(a);
    }
    int res=0;
    while(q.size()>1)
    {
        int a=q.top();q.pop();
        int b=q.top();q.pop();
        res+=a+b;
        q.push(a+b);
    }
    cout<<res<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 1343挤牛奶
 * 区间合并
*/
#define l first
#define r second 
const int N=5010;
typedef pair<int,int> PIT;
PIT a[N];
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d%d",&a[i].l,&a[i].r);

    sort(a,a+n);

    int r1=0,r2=0;
    int st=-1,ed=-1;
    for(int i=0;i<n;i++)
    {
        // cout<<"---"<<r1<<endl;
        if(ed>=a[i].l)
        {
            ed=max(ed,a[i].r);
            r1=max(r1,ed-st);
        }
        else
        {
            if(i)r2=max(r2,a[i].l-ed);
            st=a[i].l,ed=a[i].r;
            r1=max(ed-st,r1);
        }
    }

    cout<<r1<<" "<<r2<<endl;
    return 0;
}
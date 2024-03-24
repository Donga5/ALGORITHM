#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 422 校门外的树
*/
#define x first
#define y second
const int N=110;
typedef pair<int,int> PIT;
PIT a[N];
int n;
int main()
{
    int len;
    cin>>len>>n;
    for(int i=0;i<n;i++)scanf("%d%d",&a[i].x,&a[i].y);

    sort(a,a+n);
    int cnt=0;
    int st=-2e9,ed=-2e9;
    for(int i=0;i<n;i++)
    {
        int l=a[i].x,r=a[i].y;
        if(ed+1>=l)
        {
            ed=max(ed,r);
        }
        else
        {
            if(i)cnt+=ed-st+1;
            st=l,ed=r;
        }

        // printf("%d %d\n",st,ed);
    }
    cnt+=ed-st+1;
    cout<<len+1-cnt<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=6e5+10,M=2e5+10;
typedef pair<int,int> PIT;
vector<int>alls;

int b[M],c[M];

vector<int>a;
int arr[N];//转换后的数组
int n,m;

int find(int x)
{
    int l=0,r=alls.size()-1;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(alls[mid]>=x)r=mid;
        else l=mid+1;
    }
    return r+1;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a.push_back(x);
        alls.push_back(x);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        alls.push_back(b[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&c[i]);
        alls.push_back(c[i]);
    }

    //处理所有的操作数
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    //构建新的数组
    for(auto x:a)
    {
        int pos=find(x);
        arr[pos]+=1;//统计该种语言的次数，桶排序思想
    }
    
    //处理每部电影
    int r1=-1,r2=-1;
    int cnt=0;

    for(int i=1;i<=m;i++)
    {
        int t1=arr[find(b[i])];
        int t2=arr[find(c[i])];
        if(t1>r1)
        {
            r1=t1,r2=t2,cnt=i;
        }
        else if(t1==r1)
        {
            if(t2>=r2)
            {
                r1=t1,r2=t2,cnt=i;
            }
        }
    }

    cout<<cnt<<endl;
    return 0;
}
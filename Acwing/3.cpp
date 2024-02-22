//789 acwing 数的范围
#include<iostream>
using namespace std;

const int N=1e5+10;
int q[N];//存储数据
int n,m;//n表示数据的个数，m表示询问的个数

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",&q[i]);    
    
    while(m--)
    {
        int x;//询问的数字
        scanf("%d",&x);
        int l=0,r=n-1;

        //找到>=3的最小的数
        while(l<r)
        {
            int mid=l+r>>1;
            if(q[mid]>=x)r=mid;
            else l=mid+1;    
        }

        //如果x不存在话，得到q[l]>x
        if(q[l]!=x)printf("-1 -1");
        else
        {
            printf("%d ",l);
            l=0,r=n-1;
            while(l<r)
            {
                int mid=l+r+1>>1;
                if(q[mid]<=x)l=mid;
                else r=mid-1;
            }
            printf("%d\n",l);
        }
        
    }

        
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long LL;
/**
 * 4199公约数
 * 先找到最大公约数
 * 然后找到最大公约数的所有约数就是所有的公因数
 * 使用二分找到指定范围内的公因数
*/

int gcd(int a,int b)
{
    return b ? gcd(b,a%b):a;
}

void get_dividers(int x,vector<int>& nums)
{
    for(int i=1;i*i<=x;i++)
        if(x%i==0)
        {
            nums.push_back(i);
            if(x/i!=i)nums.push_back(x/i);
        }
    sort(nums.begin(),nums.end());
}

int main()
{
    int a,b;
    int l1,r1;
    int q;
    cin>>a>>b;
    cin>>q;
    vector<int>nums;
    int divider=gcd(a,b);
    get_dividers(divider,nums);
    
    // cout<<nums.size()<<endl;

    
    while(q--)
    {
        scanf("%d%d",&l1,&r1);
        // printf("%d %d\n",l1,r1);
        if(l1>divider)
        {
            puts("-1");
            continue;
        }
        if(divider<=r1)
        {
            cout<<divider<<endl;
            continue;
        }
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(nums[mid]>r1)r=mid-1;
            else l=mid;
        }   
        if(nums[r]>=l1)
        {
            cout<<nums[r]<<endl;
        }
        else puts("-1");
        
    }
    return 0;
}
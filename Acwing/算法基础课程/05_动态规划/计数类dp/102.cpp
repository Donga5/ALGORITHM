#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

/**
 * 338计数问题
*/

int get(vector<int>&num,int l, int r)
{
    int res=0;
    for(int i=l;i>=r;i--)res=res*10+num[i];
    return res;
}

int power10(int x)
{
    int res=1;
    while(x--)res*=10;
    return res;
}


int count(int a,int x)
{
    if(!a)return 0;

    int res=0;
    vector<int>nums;
    while(a)
    {
        nums.push_back(a%10);
        a/=10;
    }
    int n=nums.size();
    for(int i=n-1-!x;i>=0;i--)
    {
        if(i<n-1)//第一种情况从第二位枚举的时候才会存在(从高位开始)
        {
            res+=get(nums,n-1,i+1)*power10(i);
            if(!x)res-=power10(i);//去除前导0情况
        }
        if(nums[i]==x)res+=get(nums,i-1,0)+1;
        else if (nums[i]>x)res+=power10(i);    
    }
    return res;

}

int main()
{
    int a,b;
    while(cin>>a>>b,a||b)
    {
        if(a>b)swap(a,b);
        for(int i=0;i<=9;i++)   
            cout<<(count(b,i)-count(a-1,i))<<" ";
        puts("");
    }

    return 0;
}
#include<iostream>
#include<algorithm>

#include<vector>
using namespace std;
/**
 *869 试除法求所以的约数
 约数是一个正整数能够整除的数 
*/

vector<int> get_dividers(int x)
{
    vector<int> res;
    for(int i=1;i<=x/i;i++)
        if(x%i==0)
        {
            res.push_back(i);
            if(i!=x/i)res.push_back(x/i);
        }
    sort(res.begin(),res.end());//从小到大排序
    return res;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        auto res=get_dividers(x);
        for(auto a:res)
        {
            cout<<a<<" ";
        }
        puts(" ");
    }
    return 0;
}
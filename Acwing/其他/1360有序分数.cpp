#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/**
 * 1360有序分数
 * 1.重点要注意在unique函数的时候，结构体应当重载==
 * 2.注意最大公约数写法
 * 
 * 改进：
 * 1.可以直接将分母和分子互质的组合存下来
 * 2.另外比较函数可以通分来实现，避免精度问题
*/
double INF=1e-6;
struct num
{
    int a,b;
    bool operator < (const struct num& x)const 
    {
        return (double)a/b<(double)x.a/x.b;
    }
    bool operator == (const struct num&x)const 
    {
        return a==x.a&&b==x.b;
    }
};

int gcd(int a,int b)
{
    return b? gcd(b,a%b):a;
}

int n;
int main()
{
    cin>>n;
    vector<num>res;
    for(int i=n;i>1;i--)
    {
        for(int j=1;j<i;j++)
        {
            int t=gcd(i,j);
            res.push_back({j/t,i/t});
        }
    }
    //排序，去重
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    
    printf("0/1\n");
    for(auto t:res)
    {
        printf("%d/%d\n",t.a,t.b);
    }
    printf("1/1\n");
    

    return 0;
}
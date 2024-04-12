#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/**
 * 1229日期问题
 * 注意看清题目要求是从早到晚排列 
 * 本题目的改进方法：
 * 1.scanf直接从日期格式的字符串中读入数字
 * 另一种方法是从开始日期到结束日期直接枚举，这样就直接避免了重复以及从早到晚的输出要求。
*/
const int N=9;
char s[N];
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};


bool is_ryear(int y)
{
    return (y%4==0&&y%100!=0)||(y%400==0);
}
bool check(int y,int m,int d)
{
    if(!m||!d)return false;
    if(is_ryear(y)&&m==2)
    {
        if(d>29)return false;
        return true;    
    }
    if(m>=1&&m<=12&&d<=mon[m])
    {
        return true;
    }
    return false;
}


void print(int a,int b ,int c)
{
    // printf("%d-%d%d-%d%d\n",a,b/10,b%10,c/10,c%10);
    printf("%d-%02d-%02d\n",a,b,c);
}

int get(int a)
{
    if(a>=0&&a<=59)a=2000+a;
    else a=1900+a;
    return a;
}

int main()
{
    scanf("%s",s+1);
    int a=(s[1]-'0')*10+(s[2]-'0');
    int b=(s[4]-'0')*10+(s[5]-'0');
    int c=(s[7]-'0')*10+(s[8]-'0');
    vector<pair<int,pair<int,int>>>res;//可能出现正好三种情况一样
    
    if(check(a,b,c))res.push_back({get(a),{b,c}});
    if(check(c,a,b))res.push_back({get(c),{a,b}});
    if(check(c,b,a))res.push_back({get(c),{b,a}});
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    

    for(auto t:res)
    {
        print(t.first,t.second.first,t.second.second);
    }

    return 0;
}
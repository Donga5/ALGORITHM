#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/**
 * 466回文日期
 * 由于是回文数，只需要枚举左半边年份即可。根据年份构造出一个回文数来，
然后判断
- 该数是否是一个正常的日期
- 将日期转化成数字，比较看是否在开始和结束日期范围内即可。
*/
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int st,ed;

bool is_leap_year(int y)
{
    return (y%4==0&&y%100!=0)||(y%400==0);
}

int main()
{
    cin>>st>>ed;
    int res=0;
    int y1=st/1e4,y2=ed/1e4;
    
    for(int i=y1;i<=y2;i++)
    {
        mon[2]=28;
        if(is_leap_year(i))mon[2]=29;
        int m=i%10*10+i%100/10;
        int d=i/100%10*10+i/1000;
        if(m>=1&&m<=12&&d>=1&&d<=mon[m])
        {
            int t=i*1e4+m*100+d;
            if(t>=st&&t<=ed)res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
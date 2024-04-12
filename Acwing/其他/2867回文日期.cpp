#include<iostream>
#include<algorithm>
using namespace std;

int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int is_leap(int y)
{
    return (y%4==0&&y%100!=0)||(y%400==0);
}

/**
 * 2867回文日期
*/

bool check(int y,int m,int d)
{
    //检查日期是否合法
    mon[2]=28;
    if(is_leap(y))mon[2]=29;
    if(m<1||m>12)return false;
    if(d<1||d>mon[m])return false;
    return true;
}

int main()
{
    int st;
    cin>>st;
    bool flag1=false,flag2=false;
    int r1=0,r2=0;

    
    for(int i=st%10000;i<=9999;i++)
    {
        int y=i;
        int m=y%10*10+y%100/10;
        int d=y%1000/100*10+y/1000;
        int date=y*10000+m*100+d;
        if(!flag1&&check(y,m,d)&&date>st)
        {
            flag1=1;
            r1=date;
        }
        if(!flag2&&y/1000!=y%1000/100 && y%100==y/100 && (check(y,m,d))&&date>st)
        {
            flag2=1;
            r2=date;
        }
        
        if(flag1&&flag2)
        {
            printf("%d\n",r1);
            printf("%d\n",r2);
            break;
        }
    }
    

    return 0;
}
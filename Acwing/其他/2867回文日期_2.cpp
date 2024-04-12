#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 2867回文日期
 * 使用字符串的方式来进行处理
 * 重点要注意使用引用来处理下一天的方式，还有就是sprintf格式字符串的使用
*/
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int is_leap(int y)
{
    if((y%4==0&&y%100!=0)||(y%400==0))return 1;
    return 0;
}

int get_days(int y,int m)
{
    if(m==2)return mon[m]+is_leap(y);
    else return mon[m];
}

void next_day(int &y,int &m, int &d)
{
    //利用引用更新下一天
    d++;
    if(d>get_days(y,m))
    {
        d=1;
        m++;
        if(m>12)
        {
            m=1;
            y++;
        }
    }
}

bool check1(char s[])
{
    for(int i=1,j=8;i<=4;i++,j--)
    {
        if(s[i]!=s[j])return false;
    }
    return 1;
}
bool check2(char s[])
{
    return s[1]!=s[2]&&s[1]==s[3]&&s[2]==s[4];
}

int main()
{
    int y,m,d;
    scanf("%04d%02d%02d",&y,&m,&d);
    bool flag1=0,flag2=0;
    while(!flag1|| !flag2)
    {
        next_day(y,m,d);
        char s[10];
        sprintf(s+1,"%d%02d%02d",y,m,d);//直接将数字按照指定的格式写到字符数组
        if(check1(s))
        {
            if(!flag1)
            {
                // cout<<y<<" "<<m<<" "<<d<<endl;
                printf("%s\n",s+1);
                flag1=1;
            }
            if(check2(s)&&!flag2)
            {
                printf("%s\n",s+1);
                flag2=1;
            }
            
        }
    }





    return 0;
}


#include <iostream>
#include <algorithm>
using namespace std;

/**
 * 3498日期差值
 * 模拟，日期问题
 * 基本思路:
 * 注意考虑边界问题
*/

const int N = 8;
int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char str1[N];
char str2[N];
int y_min;

void transform(char str[],int &y1, int &m1, int &d1)
{
    int t = 0;
    for (int i = 0; i < 8; i++)
    {
        if (i == 4)
        {
            y1 = t;
            t = 0;
        }
        else if (i == 6)
        {
            m1 = t;
            t = 0;
        }
        int s = str[i] - '0';
        t = t * 10 + s;
    }
    d1 = t;
}

bool isLeapYear(int year)
{
    if (year % 4 != 0)
    {
        return false;
    }
    else if (year % 100 != 0)
    {
        return true;
    }
    else if (year % 400 != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int get_days(int y, int m, int d)
{
    int res = 0;
    if (y > y_min)
    {
        for (int i = y_min; i < y; i++)
            if (isLeapYear(i))
                res += 366;
            else
                res += 365;
    }
    if (m > 1)
    {
        for (int i = 1; i < m; i++)
        {           
            res += mon[i];
        }
        if(isLeapYear(y)&&m>2)res+=1;
    }
    res += d;
    return res;
}

int main()
{
    int y1, m1, d1;
    int y2, m2, d2;

    while (cin>>str1>>str2)
    {
        transform(str1,y1, m1, d1);
        transform(str2,y2, m2, d2);
        y_min = min(y1, y2);
        int res1 = get_days(y1, m1, d1);
        int res2 = get_days(y2, m2, d2);
        cout << abs(res2 - res1)+1 << endl;
    }
    return 0;
}
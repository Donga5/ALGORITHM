#include<iostream>
#include<algorithm>
using namespace std;

const int N=365;
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool is_leap(int y)
{
    return (y%4==0&&y%100!=0)||(y%400==0);
}

int main()
{
    int y,d;
    scanf("%d%d",&y,&d);
    if(is_leap(y))mon[2]=29;
    int t=0;
    int m=1,n=0;
    for(int i=1;i<=12;i++)
    {
        if(t<d&&t+mon[i]<d)
        {
            t+=mon[i];
            m=i+1;
        }
        else{
            n=d-t;
            break;
        }
    }
    cout<<m<<endl;
    cout<<n<<endl;
    return 0;
}
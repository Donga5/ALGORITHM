#include<iostream>
#include<vector>
using namespace std;
const int N=1e6+10;

/**
 * 高精度整数 * 低精度变量
 * 
*/

vector<int> multi(vector<int>&A, int b)
{
    vector<int>C;
    int t=0;//表示进位和中间和
    //当没有到达A的最高位以及进位不为0的时候
    for(int i=0;i<A.size() | t;i++)
    {

        if(i<A.size())t+=A[i]*b;//记得判断，否则会产生越界
        C.push_back(t%10);
        t/=10;
    }
    return C;

}

vector<int> multi1(vector<int>&A, int b)
{
    vector<int>C;
    int t=0;//表示进位和中间和
    for(int i=0;i<A.size();i++)
    {
        t+=A[i]*b;
        C.push_back(t%10);
        t/=10;
    }
    //最后处理进位
    while(t)
    {
        C.push_back(t%10);
        t/=10;
    }
    return C;
}




int main()
{
    string a;
    int b;
    cin>>a>>b;
    vector<int>A;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');

    vector<int>C= multi1(A,b);
    for(int i=C.size()-1;i>=0;i--)printf("%d",C[i]);

    return 0;
}
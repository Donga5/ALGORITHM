#include<iostream>
#include<vector>

using namespace std;
const int N=1e6+10;

vector<int> add(vector<int>& A, vector<int> &B)
{
    vector<int> C;
    int t=0;//保存和以及进位
    for(int i=0;i<A.size()||i<B.size();i++)
    {
        if(i<A.size()) t+=A[i];
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);
        t=t/10;//得到进位
    }
    if(t)C.push_back(1);
    return C;
}

/**
 * 判断了A和B的长度，后面更加简洁
*/
vector<int> add1(vector<int> &A,vector<int>&B)
{
    if(A.size()>B.size())return add1(B,A);
    vector<int>C;
    int t=0;
    for(int i=0;i<B.size();i++)
    {
        if(i<A.size())t+=A[i];
        t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    if(t)C.push_back(1);
    return C;    
}


int main()
{
    string a,b;
    cin>>a>>b;
    vector<int> A,B;

    //每一位存到数组里边
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--) B.push_back(b[i]-'0');

    auto C=add1(A,B);
    //倒序进行输出
    for(int i=C.size()-1;i>=0;i--)  printf("%d",C[i]);
    cout<<endl;
    for(auto i = C.rbegin(); i != C.rend(); i++) printf("%d", *i);
    return 0;
}
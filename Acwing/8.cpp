#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e6+10;

vector<int> div(vector<int>&A,int b, int &r)
{
    vector<int>C;
    for(int i=A.size()-1;i>=0;i--)
    {
        r=r*10+A[i];
        C.push_back(r/b);
        r=r%b;
    }

    //翻转,为了和高精度加法等保持统一
    reverse(C.begin(),C.end());

    //去除前导0
    while(C.size()>1&&C.back()==0)C.pop_back();

    return C;
}

int main()
{
    string a;
    int b;
    cin>>a>>b;
    
    vector<int> A;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    
    int r=0;
    auto C=div(A,b,r);
    
    for(int i=C.size()-1;i>=0;i--) printf("%d",C[i]);//输出商
    cout<<endl;
    cout<<r;//输出余数
    return 0;
}

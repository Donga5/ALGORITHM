#include<iostream>
#include<vector>
using namespace std;
const int N=1e6+10;

vector<int> sub(vector<int>&A, vector<int>&B)
{
    vector<int> C;
    for(int i=0,t=0;i<A.size();i++)
    {
        //t用来表示借位和差
        t=A[i]-t;
        if(i<B.size())t-=B[i];
        C.push_back((t+10)%10);//包含了t<0和t>0的两种情况,t<0需要进位+10，t>0加上10取模无影响
        
        //处理借位
        if(t<0)t=1;
        else t=0;
    }
    //处理前导零
    while(C.size()>1&&C.back()==0)C.pop_back();
    return C;
}

/**
 * 判断两个数的大小
*/
bool cmp(vector<int>&A, vector<int>&B)
{
    if(A.size()!=B.size())return A.size()>B.size();//先按照长度进行比较
    for(int i=0;i<A.size();i++)
        if(A[i]!=B[i])return A[i]>B[i];
    return true;
}
int main()
{
    string a,b;
    cin>>a>>b;
    vector<int>A,B;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');

    if(cmp(A,B))
    {
        auto C=sub(A,B);
        for(int i=C.size()-1;i>=0;i--)printf("%d",C[i]);
    }
    else
    {
        auto C=sub(B,A);
        printf("-");
        for(int i=C.size()-1;i>=0;i--)printf("%d",C[i]);
    }
    return 0;
}
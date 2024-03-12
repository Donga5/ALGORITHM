#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    int n=2e9,m=0;
    while(N--)
    {
        int a,b;
        cin>>a>>b;
        m=max(m,a/(b+1)+1);
        n=min(n,a/b);
    }
    cout<<m<<" "<<n<<endl;
    return 0;
}
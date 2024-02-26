#include<iostream>
using namespace std;
const int N=1e6+10;

int a[N];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);

    int max_count=0;
    for(int i=0;i<n-1;i++)
    {
        int j=i;
        
        while(j<n && a[j]!=a[j+1])j++;
        
        if(j-i+1>max_count)max_count=j-i+1;

        if(j=n-1)
        
        i=j;

    }
    cout<<max_count;
    return 0;
}
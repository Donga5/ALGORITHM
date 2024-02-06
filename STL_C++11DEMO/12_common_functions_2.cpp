#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;

//lowerbound & upperbound ,在指定区间（有序）内使用二分查找某个值
void demo1()
{
    int a[]={1,3,5,7,8};
    int *p=lower_bound(a,a+5,5);
    int *p1=lower_bound(a,a+5,6);
    cout<<*p<<endl;
    cout<<*p1<<endl;

    int *p2=upper_bound(a,a+5,5);
    cout<<*p2<<endl;
    
    cout<<"========="<<endl;
    //vector的情况
    vector<int> b={1,3,5,7,8};
    vector<int>::iterator p3=lower_bound(b.begin(),b.end(),6);
    cout<<*p3<<endl;

}
void demo2()
{
    
}
void demo3()
{
    
}
void demo4()
{
    
}

int main()
{
    demo1();
    // demo2();
    // demo3();
    // demo4();
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;

//reverse(begin,end)翻转，左开右闭
void demo1()
{
    vector<int> a({1,2,3,4,5,6,7,8,9});
    for(auto x :a)cout<<x<<" ";cout<<endl;
    reverse(a.begin(),a.end());
    for(auto x :a)cout<<x<<" ";cout<<endl;   

    //反转数组
    int b[]={1,2,3,4,5,6,7,8,9};
    reverse(b,b+9);
    for(auto x :b)cout<<x<<" ";cout<<endl;

    //部分翻转 
    int c[]={1,2,3,4,5,6,7,8,9};
    reverse(c,c+5);
    for(auto x :c)cout<<x<<" ";cout<<endl;
}

//unique(begin,end)。将所有不同的元素放到开头，重复的元素后移
void demo2()
{
    vector<int> a({1,2,3,3,4,4,5,6,7,7,8,9});
    int m=unique(a.begin(),a.end())-a.begin();
    cout<<m<<endl;//9
    for(auto x: a)cout<<x<<" ";cout<<endl;//1 2 3 4 5 6 7 8 9 7 8 9 

    //删除尾部的重复元素
    vector<int> a1({1,2,3,3,4,4,5,6,7,7,8,9});
    a1.erase(unique(a1.begin(),a1.end()),a1.end());
    for(auto x: a1)cout<<x<<" ";cout<<endl;//1 2 3 4 5 6 7 8 9
}
//random_shuffle
void demo3()
{
    //基于随机种子,一般把时间作为种子
    // cout<<time(0)<<endl;
    srand(time(0));


    vector<int> a({1,2,3,4,5,6,7,8,9});
    random_shuffle(a.begin(),a.end());
    for(auto x:a) cout<<x<<" ";cout<<endl;
}

bool cmp(int a,int b) //a是否应该排在b的前面
{
    return a>b;
}

//对自定义结构体进行排序
struct Rec
{
        int x,y;
        //或则可以重载小于号
        bool operator < (const Rec &b)const{
            if(x!=b.x)
            {
                return x<b.x;
            }
            return y<b.y;
        }
}c[5];


bool cmp2(Rec a, Rec b)
{
    if(a.x!=b.x)
    {
        return a.x<b.x;
    }
    return a.y<b.y;
}
//sort(begin,end,cmp)排序
void demo4()
{
    //对vector排序
    vector<int> a{1,3,2,5,4,6,7,8,9};
    // sort(a.begin(),a.end());
    // sort(a.begin(),a.end(),greater<int>()); //从大到小排序
    //sort(a.begin(),a.end(),cmp); //从大到小排序
    for(auto x:a) cout<<x<<" ";cout<<endl;

    //对数组进行排序
    int b[9]={1,3,2,5,4,6,7,8,9};
    sort(b,b+9);
    for(auto x:b) cout<<x<<" ";cout<<endl;

    
    //对结构体进行排序,也可以定义一个比较对象，不过接受参数为结构体类型
    for(int i=0;i<5;i++)
    {
        c[i].x=-i;
        c[i].y=5-i;        
    }
    // sort(c,c+5,cmp2);
    sort(c,c+5); //重载了小于号就用这个
    for(int i=0;i<5;i++)
    {
        cout<<"("<<c[i].x<<","<<c[i].y<<") "<<endl;
    }

}


int main()
{
    // demo1();
    // demo2();
    // demo3();
    demo4();
    return 0;
}
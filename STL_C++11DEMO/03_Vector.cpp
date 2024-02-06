#include<iostream>
#include<vector>
using namespace std;
/**
 * vector包含以下几部分操作:
 * 1.iterators:begin,end....
 * 2.capacity:size,max_size,resize,capacity,empty,shrink_to_fit
 * 3.element access: operator[] ,at,front,back
 * 4.modifiers:clear,insert,erase,push_back,pop_back,resize,swap
 * 
 * The time complexity for doing various operations on vectors is
 * - Random access – constant O(1)
 * - Insertion or removal of elements at the end – constant O(1)
 * - Insertion or removal of elements – linear in the distance to the end of the vector O(N)
 * - Knowing the size – constant O(1)
 * - Resizing the vector- Linear O(N)
 * 
*/

struct A{
    int a;
    int b;
};

void demo1(){
    //基本定义和初始化
    vector<int> a;
    vector<int> b(3);
    vector<int> c(10, 3);//长度为10，每个都是3
    cout<<c[1]<<endl;    
    vector<int> a1={1,2,3,4,5};
    vector<int> a2({1,2,3,4,5});
    vector<A> t={{1,2},{3,4}};//类型可以是结构体
}


void demo2(){
    //常用操作
    vector<int> a={1,2,3,4,5};
    cout<<a.size()<<endl;
    cout<<a.empty()<<endl;//判断是否为空
    a.clear();
    cout<<a.size()<<endl;
    cout<<a.empty()<<endl;
}

void demo3(){
    //迭代器演示
    vector<int> a={1,2,3,4,5};
    vector<int>::iterator it=a.begin();
    /**
     * begin,end返回的是迭代器
     * front,back直接返回的是元素
    */
    cout<<*it<<endl;
    cout<<*(a.end())<<endl;//不可取，end是最后一个元素得下一个位置,容器是前闭后开区间
    cout<<*(a.end()-1)<<endl;
    cout<<"front:"<<a.front()<<endl;//第一个元素
    cout<<"end:"<<a.back()<<endl;//最后一个元素



    //1.vector遍历
    for(vector<int>::iterator it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    cout<<"\n";
    //2.auto自动推导类型
    for(auto it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    cout<<"\n";

    //3.利用下标遍历
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";

    //4.范围遍历,但是不能修改值
    for(int x: a)
    {
         cout<<x<<" ";
    }
    cout<<"\n";

    //5.范围遍历，使用引用，可以修改值
    for(int &x:a)
    {
        x++;
        cout<<x<<" ";
    }
    cout<<endl;

    //6.范围遍历，结合auto
    for(auto x:a) cout<<x<<" ";
    cout<<endl;
}

void demo4(){
    //元素添加删除操作
    vector<int> a={1,2,3,4,5};
    a.push_back(6);
    cout<<a.back()<<endl;
    a.pop_back();
    cout<<a.back()<<endl;
}


int main()
{
    //demo1();
    //demo2();
    //demo3();
    //demo4();
    
    return 0;
}
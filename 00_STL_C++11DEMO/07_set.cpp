#include<iostream>
#include<set>
using namespace std;

/*
 * std::set是C++标准模板库(STL)中的一种关联容器，它存储的元素按照特定的排序顺序排列。
 * std::set的主要特点包括：
 * - 唯一键值：std::set中每个元素都有一个键值，且键值必须唯一，不能有重复的元素
 * - 自动排序：元素在std::set中的位置是根据它们的值自动排序的，你不能手动改变元素的位置
 * - 不可修改：std::set中的元素不能被直接修改，因为任何修改都可能改变元素的排序。如果你需要修改一个元素，你必须先删除旧的元素，然后插入新的元素
 * - 高效查找：std::set提供了高效的查找操作，它可以在对数时间内找到一个元素
 * 
 * std::set在C++的标准模板库(STL)中的典型实现是通过红黑树来实现的。红黑树是一种自平衡的二叉查找树，它可以在对数时间内完成插入、删除和查找操作，
 *   这使得std::set在处理大量数据时仍能保持高效的性能。
 * 
 * set和multiset的迭代器称为“双向访问迭代器”，不支持“随机访问”，支持星号(*)解除引用，仅支持”++”和--“两个与算术相关的操作。
 *   - 只能通过迭代器来遍历元素
 * 
*/
void demo1(){
    set<int> a;//元素不能重复
    multiset<int> b;//元素可以重复

    //使用结构体,默认需要重载 < 
    struct Rec{
        int a, b;
        bool operator < (const Rec &r)
        {
            return a < r.a;
        }
    };
    set<Rec> c;

}
void demo2()
{
    set<int>a ;
    a.insert(1);
    a.insert(5);
    a.insert(3);
    a.insert(33);
    a.insert(1);
    
    cout<<a.size()<<endl;//不能插入重复元素，不会进行报错
    cout<<a.empty()<<endl;//0
    // a.clear();
    cout<<*a.begin()<<endl;//1
    cout<<*(--a.end())<<endl;//3

    //iterator
    cout<<"iterator----\n";
    set<int>::iterator it=a.begin();
    cout<<*it<<endl;
    cout<<*(++it)<<endl;

    //循环遍历
    for(set<int>::iterator it=a.begin();it!=a.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    
}

/**
 * 元素查找
 * - find 返回的是找到元素的迭代器，找不到返回end 
*/
void demo3(){
    set<int>a ;
    a.insert(1);
    a.insert(5);
    a.insert(3);
    a.insert(33);
    a.insert(1);

   
    auto b=a.find(3);
    cout<<*b<<endl;
    b=a.find(4);//返回的是end
    cout<<*(--a.end())<<endl;
    if(a.find(4)==a.end())//利用这个来判断是否找到
    {
        cout<<"not found"<<endl;
    }

    cout<<*(a.lower_bound(3))<<endl;//返回大于等于x的最小元素迭代器
    cout<<*(a.lower_bound(4))<<endl;
    cout<<*(a.upper_bound(4))<<endl;//返回大于x的最小元素的迭代器

}

//删除元素
void demo4()
{
    set<int>a ;
    a.insert(1);
    a.insert(5);
    a.insert(3);
    a.insert(33);
    a.insert(1);

    a.erase(a.begin());//删除迭代器指向的元素
    cout<<*a.begin()<<endl;

    a.erase(5);
    cout<<(a.find(5)==a.end()?"not found":"found")<<endl;

    cout<<a.count(5)<<endl;
    cout<<a.count(33)<<endl;

}
int main()
{
    // demo1();
    //demo2();
    // demo3();
    demo4();
    return 0;
}
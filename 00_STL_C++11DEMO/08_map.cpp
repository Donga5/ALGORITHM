#include<iostream>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std;
/**
 * 底层实现键是红黑树
*/
void demo1()
{
    map<string,int>m1;
    map<int,int>m2;

    m1.insert(pair<string,int>("abc",10));
    m2.insert(pair<int,int>(1,10));
    m1.insert(pair<string,int>("Donga5",123));
    //根据键来获取值
    cout<<m1["abc"]<<endl;
    cout<<m1.at("abc")<<endl;

    cout<<m1.empty()<<endl;
    cout<<m1.size()<<endl;

    //输出iterator指向元素的key & value
    cout<<m1.begin()->first<<endl;
    cout<<m1.begin()->second<<endl;

    //find查找
    cout<<(m1.find("abc") == m1.end()? "not found":"find success")<<endl;

}


void demo2(){
    unordered_set<int>s ;//底层实现是哈希表，不支持重复
    unordered_multiset<int>s1;//底层实现是哈希表，支持重复
    unordered_map<string,int>m1;
    unordered_multimap<string,int>m2;;
}
int main()
{
    demo1();

    return 0;
}
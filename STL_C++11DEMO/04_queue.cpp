#include<iostream>
#include<queue>
using namespace std;
/**
 * 1.<queue>包含
 * - queue 循环队列
 * - priority_queue 优先队列,使用堆来进行实现，弹出时候会弹出最大值和最小值
 *   - priority_quque<int,vector<int>,less<int>> q;//最大堆,模板参数是容器类型和比较对象
 *   - priority_queue<int,vector<int>,greater<int>> q;//最小堆
 * 
 * 2.注意
 * - 没有clear函数
 * - std::queue没有提供迭代器。这是因为std::queue是一种适配器容器，
 * 它提供了特定的接口（如push(), pop(), front(), back()等），这些接口是为了满足队列这种数据结构的特性，即“先进先出”（FIFO）。
 * 因此，它并没有提供像std::vector或std::deque那样的随机访问迭代器
 * 
 * 3.queue包含的操作
 *  - 
 * 
*/
struct Rec{
    int a,b;
    //如果是大根堆需要重载<
    bool operator <(const Rec&x){
        return a<x.a;
    }
};

void demo1()
{
    //定义和初始化
    queue<int> q;
    priority_queue<int> q1;//默认是最大堆
    priority_queue<int,vector<int>,greater<int>> q2;//小根堆
    priority_queue<Rec> q3;
}

void demo2()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.pop();
    cout<<q.back()<<endl;

    
    //清空队列,没有clear函数
    q=queue<int>();
    
}

void demo3()
{
    priority_queue<int> q;
    q.push(1);
    q.push(33);
    cout<<q.top()<<endl;//取得顶部值

    priority_queue<int,vector<int>,greater<int>> q1;
    q1.push(1);
    q1.push(33);
    cout<<q1.top()<<endl;

    

}
int main()
{
    // demo1();
    // demo2();
    demo3();

    return 0;
}
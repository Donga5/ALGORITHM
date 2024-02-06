#include<iostream>
#include<deque>
using namespace std;
/**
 * deque是"double-ended queue"的缩写，意为"双端队列"。这是因为deque允许在队列的两端进行插入和删除操作。
 * 在C++的STL库中，deque是一种序列容器，它支持在头部和尾部进行快速插入和删除操作。这与vector不同，vector只支持在尾部进行快速插入和删除操作
 * 。因此，当你需要在序列的两端进行操作时，deque是一个很好的选择
 * 
 * - 支持iterator
*/
int main()
{
    deque<int> a;
    a.push_back(10);
    a.push_back(20);
    a.push_front(2);
    a.push_front(1);

    cout<<a.front()<<" "<<*(a.begin())<<endl;
    cout<<a.back()<<" "<<*(a.end()-1)<<endl;
    
    a.pop_back();
    a.pop_front();

    return 0;
}
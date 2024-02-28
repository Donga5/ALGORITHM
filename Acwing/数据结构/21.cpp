#include <iostream>
#include <string>
using namespace std;

/**
 * 827双链表
 * 用数组来模拟实现双链表
 */
const int N = 1e6 + 10;

int e[N];
int l[N], r[N], idx;

//init函数一定得记得调用，很容易忘记，
void init()
{
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

// 在第k个插入的数右边插入一个数
void add(int k, int x)
{
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    
    r[k] = idx;
    l[r[idx]] = idx;
    idx++;
}

void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    int n;
    cin >> n;
    init();

    while (n--)
    {
        string op;
        cin >> op;

        int k, x;
        if (op == "L")
        {
            cin >> x;
            add(0, x);
        }
        else if (op == "R")
        {
            cin >> x;
            add(l[1], x);
        }
        else if (op == "D")
        {
            cin >> k;
            remove(k + 1); // 是从下标为2开始存的，所以需要k+1
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else
        {
            cin >> k >> x;
            add(k + 1, x);
        }
    }


    // // 输出每个数
    for (int i = r[0]; i != 1;i=r[i])
        cout << e[i] << " ";
    return 0;
}
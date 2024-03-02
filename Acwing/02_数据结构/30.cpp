#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 838堆排序
*/
const int N=1e5;
int h[N],sz;
int n,m;

int down(int u) {
    int t = u;
    if (u * 2 <= sz && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1;//找出三个中的最小值
    
    if (u != t) {
        swap(h[u], h[t]);
        down(t);
    }
}

void up(int t)
{
    while(t/2&&h[t/2]>h[t])
    {
        swap(h[t/2],h[t]);
        t/=2;//每次都网上调整，直到到达根节点 
    }
    
}


int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    sz = n;
    for (int i = n / 2; i ; i--) down(i);  //O(n)建堆
    while (m--) {
        printf("%d ", h[1]);
        h[1] = h[sz]; sz--;
        down(1);
    }
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * 895 最长上升子序列
 * 要点
 * - 输出整个该序列,使用g[i]来记录当前状态是由谁转移过来
 */
const int N = 1010;
int a[N], f[N], g[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        g[i] = 0;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
            {
                if(f[i]<f[j]+1)
                {
                    f[i]=f[j]+1;
                    g[i]=j;
                }
            }
    }

    int k = 1;
    for (int i = 1; i <= n; i++)
        if (f[k] < f[i])
            k = i;

    for (int i = 0, len = f[k]; i < len; i++)
    {
        cout << a[k] << " ";
        k = g[k];
    }
    return 0;
}
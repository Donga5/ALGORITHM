#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PIT;

/**
 * 802.区间和，使用离散化的思路来做
 * vector<int> alls; // 存储所有待离散化的值
   sort(alls.begin(), alls.end()); // 将所有值排序
   alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素
 *
 * 基本思路：
 * 涉及到操作数字共n,2m 数值个数最多为3*1e5.可以使用离散化将2*1e9范围的数字映射到3*1e5的数组上
 * 映射到区间之后使用前缀和完成之后的查询
 * 1.存储需要离散化的数据
 * 2.单独存储需要的数据(例如x,l,r)
 * 3.将离散化数据进行排序，去重，方便按照顺序进行映射
 * 4.编写查找函数，为了是查找元素的映射位置
 * 5.构造映射数组
 * 6.构造前缀和数组
 * 7.处理查询
 *
*/

const int N = 3 * 1e5 + 10;
int a[N], s[N];   // s[N]为前缀和数组
vector<int> alls; // 存储离散化的值
vector<PIT> add, query;

// 在alls中找到x
int find(int x)
{
  int l = 0, r = alls.size() - 1;
  while (l < r)
  {
    int mid = l + r >> 1;
    if (alls[mid] >= x)
      r = mid;
    else
      l = mid + 1;
  }
  // 由于前缀和是从1开始,返回是实际上映射到a[N]中的位置
  return r + 1;
}

int main()
{
  // 存储需要离散化的数据
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    int x, c;
    scanf("%d%d", &x, &c);
    add.push_back({x, c});
    alls.push_back(x);
  }
  for (int i = 0; i < m; i++)
  {
    int l, r;
    scanf("%d%d", &l, &r);
    query.push_back({l, r});
    alls.push_back(l);
    alls.push_back(r);
  }

  // 数组排序，去重
  sort(alls.begin(), alls.end());
  alls.erase(unique(alls.begin(), alls.end()), alls.end()); // unique第一个重复元素的迭代器

  // 构建映射数组
  for (auto item : add)
  {
    int x = find(item.first); // 找到映射的位置
    a[x] += item.second;
  }
  // 构建前缀和数组
  for (int i = 1; i <= alls.size(); i++)
    s[i] = s[i - 1] + a[i];

  // 利用前缀和数组完成查询
  for (auto item : query)
  {
    //查找l和r的位置
    int l=find(item.first),r=find(item.second);
    printf("%d\n",s[r]-s[l-1]);
  }

  return 0;
}
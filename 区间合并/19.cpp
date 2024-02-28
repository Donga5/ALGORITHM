#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;


/**
 * 区间合并
 * 关键思路：
 * 1.利用pair来存储每个区间，
 * 2.然后将区间按照左端点进行排序
 * 3.每次从左到右维护一个区间，判断和后边紧邻区间的关系来更新维护区间
*/
const int N=1e6+10;
typedef pair<int,int> PIT;
vector<PIT>segs;

void merge_seg(vector<PIT>& segs)
{
    vector<PIT> res;
    int start=-2e9,end=-2e9;
    for(auto seg:segs)
    {
        if(end<seg.first)
        {
            if(start!=-2e9)res.push_back({start,end});
            start=seg.first;
            end=seg.second;//维护区间更新为后边的那个区间
        }
        else
            end=max(end,seg.second);
    }
    //将最后的区间进行加入到答案中去
    if(start!=-2e9)res.push_back({start,end});
    segs=res;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        segs.push_back({l,r});
    }
    //对pair进行排序,先按照第一个关键子进行排序，然后再按照第二个关键字进行排序
    sort(segs.begin(),segs.end());
    merge_seg(segs);

    cout<<segs.size()<<endl;   
    return 0;
}
#include<iostream>
using namespace std;

const int N=1e6+10;

int a[N],s[N];//S[N]使用桶排序的思想来动态记录每个数字，出现的次数,以空间换时间，
//本题目的数值是1e6 可以开数组来做
int main()
{
    int n;
    int res=1;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);

    for(int i=0,j=0;i<n;i++)
    {
        s[a[i]]++;
        while(s[a[i]]>1)//说明有重复元素
        {
            //随着j的移动，s[]表示的当前[i,j]区间内的数的出现的重复次数，当循环停止的时候，消除了重复元素
            s[a[j]]--;
            j++; 
        }
        res=max(res,i-j+1);
    }
    cout<<res<<endl;

    return 0;
}
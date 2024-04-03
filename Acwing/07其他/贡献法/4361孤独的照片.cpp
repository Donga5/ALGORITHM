#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/**
 * 4361孤独的照片
 * 贡献法
 * 基本思路:
 * 1.先预处理出来对于每个位置的数左边和右边的与当前不相同的字母的连续个数
 * 2.将三种情况相加，看左边和右边能够贡献多少个字母
 * 
*/
typedef long long LL;
const int N=5e5+10;
char str[N];
int l[N],r[N];//l左边有多少个与连续的当前不相同的数字

int main()
{
    int n;
    cin>>n;
    scanf("%s",str);
    for(int i=0,h=0,g=0;i<n;i++)
        if(str[i]=='G')l[i]=h,h=0,g++;
        else l[i]=g,g=0,h++;
    for(int i=n-1,h=0,g=0;i>=0;i--)
        if(str[i]=='G')r[i]=h,h=0,g++;
        else r[i]=g,g=0,h++;
    
    //统计数量
    LL res=0;
    for(int i=0;i<n;i++)
        res+=(LL)l[i]*r[i]+(LL)max(0,l[i]-1)+(LL)max(0,r[i]-1);
    cout<<res<<endl;
    return 0;
}
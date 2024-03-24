#include<iostream>
#include<algorithm>
using namespace std;

/**]
 * 4405统计子矩阵
 * 优化，利用双指针，只记录列的前缀和
*/
const int N=505;
typedef long long LL;
LL s[N][N];

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%lld",&s[i][j]);
            s[i][j]+=s[i-1][j];
        }
    }

    LL cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            for(int l=1,r=1,s1=0;r<=m;r++)
            {
                s1+=s[j][r]-s[i-1][r];
                while(s1>k)
                {
                    s1-=s[j][l]-s[i-1][l];
                    l++;
                }
                cnt+=r-l+1;//思考双指针的单调性,此时的l和r构成的区间一定是小于k,如果l继续往右移动，得到的区间也肯定符合条件，因为区间内所有数都是正数
            }
        }
    }
    cout<<cnt<<endl;
    
    return 0;
}
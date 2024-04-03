
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

/**
 * 2868子串分值
*/
const int N=1e6+10;
char str[N];
int cnt[26];
typedef long long LL;

int main()
{
    scanf("%s",str);

    LL res=0;
    for(int i=0;str[i];i++)
    {
        int t=0;
        memset(cnt,0,sizeof(cnt));
        for(int j=0;str[j];j++)
        {
            int s=str[j]-'a';
            if(cnt[s])
            {
                t--;
            }   
        }
    }
    return 0;
}
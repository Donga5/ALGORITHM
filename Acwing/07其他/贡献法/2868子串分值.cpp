#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
/**
 * 2868子串分值
 * 贡献法
 * 1.思考单个字母对于答案的贡献
 * 2.什么情况下能够贡献，能够贡献多少个
 * 3.考虑边界情况。
*/
const int N=1e6+10;
typedef long long LL;
int l[N],r[N],p[26];//临时数组，存储每个字母出现的位置三
char str[N];

int main()
{
    scanf("%s",str+1);
    int n=strlen(str+1);
    
    for(int i=1;i<=n;i++)
    {
        int t=str[i]-'a';
        l[i]=p[t];
        p[t]=i;
    }
    for(int i=0;i<26;i++)p[i]=n+1;//边界情况设置为n+1
    for(int i=n;i;i--)
    {
        int t=str[i]-'a';
        r[i]=p[t];
        p[t]=i;
    }


    LL res=0;
    for(int i=1;i<=n;i++)res+=(LL)(i-l[i])*(r[i]-i);
    cout<<res<<endl;

    return 0;
}
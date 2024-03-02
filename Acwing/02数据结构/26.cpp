#include<iostream>
using namespace std;

/**
 * 831.kmp字符串
*/
const int N=1e5+10,M=1e6+10;
char p[N];//模式串
char s[M];//字符串
int ne[N];//next数组，表示在i为结尾的子串中相等最长前缀和最长后缀的长度

int n,m;
int main()
{
    cin >> n >> p + 1 >> m >> s + 1;//输入的模式串和字符串从下标为1的位置开始输入
    //或者是使用scanf("%d%s%d%s", &n, p + 1, &m, s + 1);

    //构造next数组
    for(int i=2,j=0;i<=n;i++)
    {
        while(j&&p[i]!=p[j+1])j=ne[j];
        if(p[i]==p[j+1])j++;//如果相同，则最长的相等前后缀+1
        ne[i]=j;
    }
    
    //kmp匹配,j从0开始
    for(int i=1,j=0;i<=m;i++)
    {
        while(j && s[i] != p[j+1])j=ne[j];//如果不匹配，通过循环ne[j]找到合适的重新开始匹配的位置
        if(s[i]==p[j+1])j++;
        if(j==n)
        {
            //匹配成功，注意题目的下标从0开
            printf("%d ",(i-n+1)-1);
            j=ne[j];
        }
    }

    return 0;
}